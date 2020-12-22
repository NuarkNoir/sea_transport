#include "adminpanel.h"
#include "ui_adminpanel.h"


AdminPanel::AdminPanel(QWidget *parent) : QMainWindow(parent), ui(new Ui::AdminPanel) {
    ui->setupUi(this);


    connect(ui->pb_logout, &QPushButton::clicked, this, &AdminPanel::on_logout_requested);

    connect(ui->pb_vessels_add, &QPushButton::clicked, this, [this](){
        this->on_vessel_add_edit(false);
    });
    connect(ui->pb_vessels_edit, &QPushButton::clicked, this, [this](){
        this->on_vessel_add_edit(true);
    });
    connect(ui->pb_vessels_remove, &QPushButton::clicked, this, &AdminPanel::on_vessel_remove);

    connect(ui->pb_users_add, &QPushButton::clicked, this, [this](){
        this->on_user_add_edit(false);
    });
    connect(ui->pb_users_edit, &QPushButton::clicked, this, [this](){
        this->on_user_add_edit(true);
    });
    connect(ui->pb_users_remove, &QPushButton::clicked, this, &AdminPanel::on_user_remove);

    connect(ui->pb_dp_add, &QPushButton::clicked, this, [this](){
        this->on_delivery_point_add_edit(false);
    });
    connect(ui->pb_dp_edit, &QPushButton::clicked, this, [this](){
        this->on_delivery_point_add_edit(true);
    });
    connect(ui->pb_dp_remove, &QPushButton::clicked, this, &AdminPanel::on_delivery_point_remove);


    uvm = new UsersViewModel(this);
    ui->tv_users->setModel(this->uvm);

    vvm = new VesselsViewModel(this);
    ui->tv_vessels->setModel(vvm);

    dpvm = new DeliveryPointsViewModel(this);
    ui->tv_dp->setModel(dpvm);

    connect(ui->tv_users->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        ui->pb_users_remove->setEnabled(selected.length() > 0);
        ui->pb_users_edit->setEnabled(selected.length() == 1);
    });

    connect(ui->tv_vessels->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        ui->pb_vessels_remove->setEnabled(selected.length() > 0);
        ui->pb_vessels_edit->setEnabled(selected.length() == 1);
    });

    connect(ui->tv_dp->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        ui->pb_dp_remove->setEnabled(selected.length() > 0);
        ui->pb_dp_edit->setEnabled(selected.length() == 1);
    });

    ui->tw_tabs->setCurrentIndex(0);
}

AdminPanel::~AdminPanel() {
    delete ui;

    delete uvm;
    delete vvm;
    delete dpvm;
}

AdminPanel& AdminPanel::set_user(const user_entity &user) {
    this->user = user;
    ui->lab_user->setText(tr("Hello, **%1**").arg(user.login()));
    return *this;
}

void AdminPanel::on_logout_requested() {
    this->close();
}

void AdminPanel::on_vessel_add_edit(bool /*edit*/) {

}

void AdminPanel::on_vessel_remove() {
    auto selected = ui->tv_vessels->selectionModel()->selectedRows();
    if (selected.length() == 0) {
        return;
    }

    QMessageBox delConf(this);
    delConf.setIcon(QMessageBox::Question);
    delConf.setWindowTitle(tr("Deletion confirmation"));
    delConf.setText(tr("Are you sure you want to delete these vessels?"));
    delConf.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    delConf.setDefaultButton(QMessageBox::No);
    if (delConf.exec() == QMessageBox::No) {
        return;
    }

    foreach (auto mIdx, selected) {
        int idx = mIdx.row();
        qDebug() << idx << ' ' << mIdx.data() << '\n';
    }

    vvm->update();
}

void AdminPanel::on_user_add_edit(bool edit) {
    auto selected = ui->tv_users->selectionModel()->selectedRows();
    if (edit && selected.length() != 1) {
        return;
    }

    user_entity usr;
    if (edit) {
        int idx = selected[0].row();
        usr = apparatus::instance()->get_auth_subsystem()->users()[idx];
        if (usr.id() == this->user.id()) {
            QMessageBox::critical(this, "Error", "You cannot edit yourself");
            return;
        }
    }

    UserEditDialog ued(this);
    ued.setWindowTitle(edit? "Edit user" : "New user");
    ued.set_user(&usr, edit);
    if (ued.exec() != UserEditDialog::Accepted) {
        return;
    }

    auto data = ued.user_data();
    if (edit) {
        bool success;
        auto user = apparatus::instance()->get_auth_subsystem()->get_user(usr.login(), success);
        if (success) {
            user->set_password(data->password);
            user->set_role(data->role);
            QMessageBox::information(this, "Info", "User edited successfully (note: you cannot change login)");
        }
        else {
            QMessageBox::critical(this, "Error", "Error while editing user");
            return;
        }
    }
    else {
        bool success = apparatus::instance()->get_auth_subsystem()->register_user(data->login, data->password, data->role);
        if (success) {
            QMessageBox::information(this, "Info", "User created successfully");
        }
        else {
            QMessageBox::critical(this, "Error", "Error while creating user");
            return;
        }
    }

    uvm->update();
}

void AdminPanel::on_user_remove() {
    auto selected = ui->tv_users->selectionModel()->selectedRows();
    if (selected.length() == 0) {
        return;
    }

    QMessageBox delConf(this);
    delConf.setIcon(QMessageBox::Question);
    delConf.setWindowTitle(tr("Deletion confirmation"));
    delConf.setText(tr("Are you sure you want to delete these users?"));
    delConf.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    delConf.setDefaultButton(QMessageBox::No);
    if (delConf.exec() == QMessageBox::No) {
        return;
    }

    auto _u = apparatus::instance()->get_auth_subsystem()->users();
    foreach (auto mIdx, selected) {
        int idx = mIdx.row();
        auto ent = _u[idx];
        if (ent.id() == user.id()) {
            QMessageBox::critical(this, "Error", "You cannot delete yourself!");
            break;
        }
        apparatus::instance()->get_auth_subsystem()->remove_user(ent.login());
    }

    uvm->update();
}

void AdminPanel::on_delivery_point_add_edit(bool edit) {
    auto selected = ui->tv_dp->selectionModel()->selectedRows();
    if (edit && selected.length() != 1) {
        return;
    }

    dpoint_entity dpoint;
    if (edit) {
        int idx = selected[0].row();
        dpoint = apparatus::instance()->get_object_subsystem()->dpoints()[idx];
    }

    DeliveryPointEditDialog dped(this);
    dped.setWindowTitle(edit? "Edit delivery point" : "New delivery point");
    dped.set_dpoint(&dpoint, edit);
    if (dped.exec() != UserEditDialog::Accepted) {
        return;
    }

    auto data = dped.dpoint();
    if (edit) {
        bool success;
        auto dp = apparatus::instance()->get_object_subsystem()->get_dpoint(dpoint.id(), success);
        if (!success) {
            QMessageBox::critical(this, "Error", "Error editing delivery point");
            return;
        }

        dp->set_title(data->title());
        dp->set_storages(data->storages());
    }
    else {
        apparatus::instance()->get_object_subsystem()->add_dpoint(*data);
    }

    dpvm->update();
}

void AdminPanel::on_delivery_point_remove() {
    auto selected = ui->tv_dp->selectionModel()->selectedRows();
    if (selected.length() == 0) {
        return;
    }

    QMessageBox delConf(this);
    delConf.setIcon(QMessageBox::Question);
    delConf.setWindowTitle(tr("Deletion confirmation"));
    delConf.setText(tr("Are you sure you want to delete these delivery points?"));
    delConf.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    delConf.setDefaultButton(QMessageBox::No);
    if (delConf.exec() == QMessageBox::No) {
        return;
    }

    foreach (auto mIdx, selected) {
        entity_id oid = mIdx.data().toULongLong();
        apparatus::instance()->get_object_subsystem()->remove_dpoint(oid);
    }

    dpvm->update();
}
