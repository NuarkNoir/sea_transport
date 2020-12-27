#include "skipperpanel.h"
#include "ui_skipperpanel.h"


SkipperPanel::SkipperPanel(QWidget *parent) : QMainWindow(parent), ui(new Ui::SkipperPanel) {
    ui->setupUi(this);


    connect(ui->pb_logout, &QPushButton::clicked, this, &SkipperPanel::on_logout_requested);

    cvm = new CargoViewModel(this);
    ui->tv_cargo->setModel(this->cvm);
}

SkipperPanel::~SkipperPanel() {
    delete ui;

    delete cvm;
}

SkipperPanel& SkipperPanel::set_user(const user_entity &user) {
    this->user = user;
    ui->lab_user->setText(tr("Hello, **%1**").arg(user.login()));

    emit user_set();

    return *this;
}

void SkipperPanel::on_user_set() {
    UserRole urole = this->user.role();
    switch (urole) {
        case UserRole::ADMINISTRATOR:
        case UserRole::DISPATCHER:
            QMessageBox::critical(this, "Error", "You shouldn't be here!");
            close();
            return;
        case UserRole::SKIPPER:
            break;
    }

    bool success = false;
    vessel_entity vessel;
    foreach(auto _vessel, apparatus::instance()->get_object_subsystem()->vessels()) {
        if (_vessel.skipper() == this->user.login()) {
            success = true;
            vessel = _vessel;
            break;
        }
    }

   if (!success) {
        QMessageBox::critical(this, "Error", "You are not assigned to vessel. \n"
                                             "Ask you local dispatcher/administrator to do it. \n"
                                             "System will now close.");
        this->close();
   }

   ui->lab_vid->setText(QString::number(vessel.id()));

   bool h_success;
   auto harbor = apparatus::instance()->get_object_subsystem()->get_dpoint(vessel.harbor(), h_success);
   ui->lab_harbor->setText(h_success? harbor->title() : "#UNKNOWN#");

   int cap_used = 0;
   foreach (auto c, vessel.cargo()) {
       cap_used += c.volume();
   }
   ui->lab_capacity->setText(tr("%1/%2/%3").arg(cap_used, vessel.capacity(), vessel.capacity() + cap_used));

   this->cvm->set_data(vessel.cargo());
}

void SkipperPanel::on_logout_requested() {
    this->close();
}
