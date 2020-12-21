#include "authwindow.h"
#include "ui_authwindow.h"


AuthWindow::AuthWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::AuthWindow) {
    ui->setupUi(this);

    connect(ui->btn_login, &QPushButton::clicked, this, &AuthWindow::on_auth_requested);
}

AuthWindow::~AuthWindow() {
    delete ui;
}

void AuthWindow::on_auth_requested() {
    auto login = ui->et_login->text().trimmed();
    auto passw = ui->et_password->text().trimmed();

    if (login.isEmpty() || passw.isEmpty()) {
        QMessageBox::critical(this, "Error", "Login nor password cannot be empty!");
        return;
    }

    bool success = false;
    auto a = apparatus::instance()->get_auth_subsystem();
    if (apparatus::isFirstRun()) {
        success = a.register_user(login, passw, UserRole::ADMINISTRATOR);
        if (!success) {
            QMessageBox::critical(this, "Error", "Cannot register you. Check filesystem permission");
            return;
        }
        else {
            QMessageBox::information(this, "Info", "You are the first user of system. "
                                                   "Your account type is administrator");
        }
    }

    auto user = a.get_user(login, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "User not found");
        return;
    }

    success = user->verify_password(passw);
    if (!success) {
        QMessageBox::critical(this, "Error", "Wrong password");
        return;
    }


    if (user->role() == UserRole::ADMINISTRATOR) {
        AdminPanel(nullptr).set_user(*user).showNormal();
    }
    else if (user->role() == UserRole::DISPATCHER) {
        //  DispatcherPanel(nullptr, user).set_user(user).show();
    }
    else if (user->role() == UserRole::SKIPPER) {
        //  SkipperPanel(nullptr, user).set_user(user).show();
    }
    else {
        QMessageBox::critical(this, "Error", "Deserialized user have wrong type. "
                                             "It may mean corruption of data.");
        return;
    }
}
