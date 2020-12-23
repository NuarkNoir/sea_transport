#include "vesseleditdialog.h"
#include "ui_vesseleditdialog.h"

VesselEditDialog::VesselEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::VesselEditDialog) {
    ui->setupUi(this);

    this->cvm = new CargoViewModel(this);
    ui->tv_cargo->setModel(this->cvm);

    connect(ui->tv_cargo->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        ui->pb_cargo_remove->setEnabled(selected.length() > 0);
    });

    connect(ui->pb_cargo_remove, &QPushButton::clicked, [this]() {
        auto sel = ui->tv_cargo->selectionModel()->selectedRows();
        if (sel.length() == 0) {
            return;
        }

        foreach (auto mIdx, sel) {
            auto oid = mIdx.data().toULongLong();
            bool success;
            this->_vessel->withdraw_cargo(oid, success);
            if (!success) {
                QMessageBox::critical(this, "Error", "Cannot remove some of this cargo!");
            }
        }
    });

    foreach (auto port, apparatus::instance()->get_object_subsystem()->dpoints()) {
        ui->cb_port->addItem(tr("%1 :%2").arg(port.title()).arg(port.id()));
    }

    foreach (auto user, apparatus::instance()->get_auth_subsystem()->users()) {
        if (user.role() != UserRole::SKIPPER) {
            continue;
        }
        ui->cb_skippers->addItem(tr("%1 :%2").arg(user.login()).arg(user.id()));
    }

    connect(ui->pb_cargo_add, &QPushButton::clicked, this, &VesselEditDialog::on_cargo_add);

    connect(ui->pb_withdraw_from_harbor, &QPushButton::clicked, this, &VesselEditDialog::on_withdraw_from_harbor);
    connect(ui->pb_withdraw_from_vessel, &QPushButton::clicked, this, &VesselEditDialog::on_withdraw_from_vessel);

    connect(ui->pb_save, &QPushButton::clicked, this, &VesselEditDialog::accept);
    connect(ui->pb_discard, &QPushButton::clicked, this, &VesselEditDialog::reject);
}

VesselEditDialog::~VesselEditDialog() {
    delete ui;
}

void VesselEditDialog::select_proper_skipper() {
    int i = 0;
    foreach (auto user, apparatus::instance()->get_auth_subsystem()->users()) {
        if (user.role() != UserRole::SKIPPER || user.login() != this->_vessel->skipper()) {
            i += 1;
            continue;
        }
        ui->cb_port->setCurrentIndex(i);
        return;
    }

    QMessageBox::critical(this, "Error", "Cannot find this vessel's skipper.");
}

void VesselEditDialog::select_proper_port() {
    int i = 0;
    foreach (auto port, apparatus::instance()->get_object_subsystem()->dpoints()) {
        if (port.id() != this->_vessel->harbor()) {
            i += 1;
            continue;
        }
        ui->cb_port->setCurrentIndex(i);
        return;
    }

    QMessageBox::critical(this, "Error", "Cannot find this vessel's harbor.");
}

vessel_entity* VesselEditDialog::vessel() {
    return this->_vessel;
}

void VesselEditDialog::set_vessel(vessel_entity *ves, bool edit) {
    this->_vessel = new vessel_entity(*ves);

    if (edit) {
        this->select_proper_skipper();
        this->select_proper_port();
        ui->sb_capacity->setValue(this->_vessel->capacity());
        this->cvm->set_data(this->_vessel->cargo());
        ui->pb_withdraw_from_harbor->setEnabled(true);
        ui->pb_withdraw_from_vessel->setEnabled(true);
    }
    ui->lab_capacity_current->setText(QString::number(this->_vessel->capacity()));
}

void VesselEditDialog::on_cargo_add() {
    CargoEditDialog ced(this);
    ced.setWindowTitle("New cargo");
    if (ced.exec() != CargoEditDialog::Accepted) {
        return;
    }

    bool success;
    this->_vessel->add_cargo(*ced.cargo(), success);
    if (success) {
        this->cvm->set_data(this->_vessel->cargo());
        QMessageBox::information(this, "Success", "Cargo successfully put into storage");
    }
    else {
        QMessageBox::critical(this, "Error", "Not enough space to put cargo");
    }
}

void VesselEditDialog::on_withdraw_from_harbor() {
    QMessageBox::information(this, "Note", "Please note, old storage will be used.\n"
                                           "Also, movement cannot be undone by discarding vessel edit dialog");

    bool success;
    auto dpoint = apparatus::instance()->get_object_subsystem()->get_dpoint(this->_vessel->harbor(), success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot find associated harbor in DB");
        return;
    }
    if (dpoint->storages().isEmpty()) {
        QMessageBox::information(this, "Note", "Vessel has no storages");
        return;
    }

    QStringList harbor_storage;
    foreach (auto storage, dpoint->storages()) {
        harbor_storage << QString::number(storage.id());
    }
    bool ok;
    QString storage_id_str = QInputDialog::getItem(this, "Select storage", "Storages in harbor:", harbor_storage, 0, false, &ok);
    if (!ok || storage_id_str.isEmpty()) {
        QMessageBox::information(this, "Aborted", "Operation aborted by user.");
        return;
    }

    entity_id sid = storage_id_str.toULongLong();
    auto storage = dpoint->get_storage(sid, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot find associated storage in harbor");
        return;
    }
    if (storage->cargo().isEmpty()) {
        QMessageBox::information(this, "Note", "Storage has no cargo");
        return;
    }

    QStringList storage_cargo;
    foreach (auto storage, storage->cargo()) {
        storage_cargo << tr("%1 :%2").arg(storage.title()).arg(storage.id());
    }
    QString cargo_id_str = QInputDialog::getItem(this, "Select cargo", "Cargo in storage:", storage_cargo, 0, false, &ok);
    if (!ok || cargo_id_str.isEmpty()) {
        QMessageBox::information(this, "Aborted", "Operation aborted by user.");
        return;
    }

    entity_id cid = cargo_id_str.split(":")[1].toULongLong();
    auto cargo = storage->get_cargo(cid, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot find cargo in storage");
        return;
    }

    this->_vessel->add_cargo(cargo, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot add cargo to vessel");
        return;
    }
    storage->withdraw_cargo(cid, success);
    if (!success) {
        throw std::runtime_error("Cannot withdraw from storage");
    }

    QMessageBox::information(this, "Info", "Successfully withdrawed cargo from harbor");
    cvm->set_data(this->_vessel->cargo());
}

void VesselEditDialog::on_withdraw_from_vessel() {
    if (this->_vessel->cargo().isEmpty()) {
        QMessageBox::information(this, "Note", "Vessel has no cargo");
        return;
    }

    QMessageBox::information(this, "Note", "Please note, old storage will be used.\n"
                                           "Also, movement cannot be undone by discarding vessel edit dialog");

    bool success;
    auto dpoint = apparatus::instance()->get_object_subsystem()->get_dpoint(this->_vessel->harbor(), success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot find associated harbor in DB");
        return;
    }

    QStringList vessel_cargo;
    foreach (auto storage, this->_vessel->cargo()) {
        vessel_cargo << tr("%1 :%2").arg(storage.title()).arg(storage.id());
    }
    bool ok;
    QString cargo_id_str = QInputDialog::getItem(this, "Select cargo", "Cargo in storage:", vessel_cargo, 0, false, &ok);
    if (!ok || cargo_id_str.isEmpty()) {
        QMessageBox::information(this, "Aborted", "Operation aborted by user.");
        return;
    }

    entity_id cid = cargo_id_str.split(":")[1].toULongLong();
    auto cargo = this->_vessel->get_cargo(cid, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot find cargo in vessel");
        return;
    }

    QStringList harbor_storage;
    foreach (auto storage, dpoint->storages()) {
        harbor_storage << QString::number(storage.id());
    }
    QString storage_id_str = QInputDialog::getItem(this, "Select storage", "Storages in harbor:", harbor_storage, 0, false, &ok);
    if (!ok || storage_id_str.isEmpty()) {
        QMessageBox::information(this, "Aborted", "Operation aborted by user.");
        return;
    }
    entity_id sid = storage_id_str.toULongLong();
    auto storage = dpoint->get_storage(sid, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot find associated storage in harbor");
        return;
    }

    storage->add_cargo(cargo, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "Cannot add cargo to storage");
        return;
    }
    this->_vessel->withdraw_cargo(cid, success);
    if (!success) {
        throw std::runtime_error("Cannot withdraw from vessel");
    }

    QMessageBox::information(this, "Info", "Successfully withdrawed cargo from vessel");
    cvm->set_data(this->_vessel->cargo());
}

void VesselEditDialog::accept() {
    int cvs = 0;
    foreach (auto c, this->_vessel->cargo()) {
        cvs += c.volume();
    }
    if (cvs > ui->sb_capacity->value()) {
        QMessageBox::critical(this, "Error", "Cargo volume bigger than capacity");
        return;
    }

    auto slog = ui->cb_skippers->currentText().split(":")[0].trimmed();
    auto hid = ui->cb_port->currentText().split(":")[1].trimmed().toULongLong();
    auto cap = ui->sb_capacity->value();

    this->_vessel->set_skipper(slog);
    this->_vessel->set_harbor(hid);
    this->_vessel->set_capacity(cap);

    QDialog::accept();
}
