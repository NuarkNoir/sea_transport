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
        success = a->register_user(login, passw, UserRole::ADMINISTRATOR);
        if (!success) {
            QMessageBox::critical(this, "Error", "Cannot register you. Check filesystem permission");
            return;
        }
        else {
            QMessageBox::information(this, "Info", "You are the first user of system. "
                                                   "Your account type is administrator");
        }

        apparatus::instance()->save();
    }

    auto user = a->get_user(login, success);
    if (!success) {
        QMessageBox::critical(this, "Error", "User not found");
        return;
    }

    success = user->verify_password(passw);
    if (!success) {
        QMessageBox::critical(this, "Error", "Wrong password");
        return;
    }


    QWidget *w;
    if (user->role() == UserRole::ADMINISTRATOR) {
        w = new AdminPanel(nullptr);
        ((AdminPanel*) w)->set_user(*user);
    }
    else if (user->role() == UserRole::DISPATCHER) {
        w = new AdminPanel(nullptr);
        ((AdminPanel*) w)->set_user(*user);
    }
    else if (user->role() == UserRole::SKIPPER) {
        QMessageBox::information(this, "Info", "Please note: if you have more than one vessel assigned to you "
                                               "only first will be shown (it is intended by design, you cannot physically control two ships). \n"
                                               "Please, ask your local dispatcher/administrator to unassign you from other vessels.");
        w = new SkipperPanel(nullptr);
        ((SkipperPanel*) w)->set_user(*user);
    }
    else {
        QMessageBox::critical(this, "Error", "Deserialized user have wrong type. "
                                             "It may mean corruption of data.");
        return;
    }

    w->show();
    close();
}
