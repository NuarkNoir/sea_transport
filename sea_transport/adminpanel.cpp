#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) : QMainWindow(parent), ui(new Ui::AdminPanel) {
    ui->setupUi(this);

    connect(ui->pb_logout, &QPushButton::clicked, this, &AdminPanel::on_logout_requested);

    connect(ui->pb_vessels_add, &QPushButton::clicked, this, &AdminPanel::on_vessel_add);
    connect(ui->pb_vessels_remove, &QPushButton::clicked, this, &AdminPanel::on_vessel_remove);

    connect(ui->pb_users_add, &QPushButton::clicked, this, &AdminPanel::on_user_add);
    connect(ui->pb_users_remove, &QPushButton::clicked, this, &AdminPanel::on_user_remove);

    connect(ui->pb_users_add, &QPushButton::clicked, this, &AdminPanel::on_storage_add);
    connect(ui->pb_users_remove, &QPushButton::clicked, this, &AdminPanel::on_storage_remove);

    connect(ui->pb_dp_add, &QPushButton::clicked, this, &AdminPanel::on_delivery_point_add);
    connect(ui->pb_dp_remove, &QPushButton::clicked, this, &AdminPanel::on_delivery_point_remove);

//    ui->tv_vessels->setModel();
//    ui->tv_users->setModel();
//    ui->tv_dp->setModel();
//    ui->tv_storages->setModel();
}

AdminPanel::~AdminPanel() {
    delete ui;
}

AdminPanel& AdminPanel::set_user(const user_entity &user) {
    this->user = user;
    ui->lab_user->setText(tr("Hello user %1").arg(user.login()));
    return *this;
}
