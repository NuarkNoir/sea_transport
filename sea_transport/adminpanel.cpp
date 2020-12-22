#include "adminpanel.h"
#include "ui_adminpanel.h"
#include <QStringListModel >

AdminPanel::AdminPanel(QWidget *parent) : QMainWindow(parent), ui(new Ui::AdminPanel) {
    ui->setupUi(this);


//    connect(ui->pb_logout, &QPushButton::clicked, this, &AdminPanel::on_logout_requested);

//    connect(ui->pb_vessels_add, &QPushButton::clicked, this, &AdminPanel::on_vessel_add);
//    connect(ui->pb_vessels_remove, &QPushButton::clicked, this, &AdminPanel::on_vessel_remove);

//    connect(ui->pb_users_add, &QPushButton::clicked, this, &AdminPanel::on_user_add);
//    connect(ui->pb_users_remove, &QPushButton::clicked, this, &AdminPanel::on_user_remove);

//    connect(ui->pb_dp_add, &QPushButton::clicked, this, &AdminPanel::on_delivery_point_add);
//    connect(ui->pb_dp_remove, &QPushButton::clicked, this, &AdminPanel::on_delivery_point_remove);


    uvm = new UsersViewModel(this);
    ui->tv_users->setModel(this->uvm);

    vvm = new VesselsViewModel(this);
    ui->tv_vessels->setModel(vvm);

    dpvm = new DeliveryPointsViewModel(this);
    ui->tv_dp->setModel(dpvm);


    uvm->update();
    vvm->update();
    dpvm->update();
}

AdminPanel::~AdminPanel() {
    delete ui;

    delete uvm;
}

AdminPanel& AdminPanel::set_user(const user_entity &user) {
    this->user = user;
    ui->lab_user->setText(tr("Hello user %1").arg(user.login()));
    return *this;
}

void AdminPanel::on_logout_requested() {

}

void AdminPanel::on_vessel_add() {

}

void AdminPanel::on_vessel_remove() {

}

void AdminPanel::on_user_add() {

}

void AdminPanel::on_user_remove() {

}

void AdminPanel::on_delivery_point_add() {

}

void AdminPanel::on_delivery_point_remove() {

}
