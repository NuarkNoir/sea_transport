#include "usereditdialog.h"
#include "ui_usereditdialog.h"


UserEditDialog::UserEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::UserEditDialog) {
    ui->setupUi(this);

    connect(ui->btn_save, &QPushButton::clicked, this, &UserEditDialog::accept);
    connect(ui->btn_discard, &QPushButton::clicked, this, &UserEditDialog::reject);
}

UserEditDialog::~UserEditDialog() {
    delete ui;
}

user_data_struct* UserEditDialog::user_data() const {
    return this->_user_data;
}

void UserEditDialog::set_user(user_entity* user, bool edit) {
    if (edit) {
        this->_user_data = new user_data_struct();

        ui->et_login->setText(user->login());
        ui->et_password->setText("##########UNEDITED##########");
        ui->cb_role->setCurrentIndex((int)user->role());
    }
    else {
        this->_user_data = new user_data_struct{};
    }
    this->_user_data->edit = edit;
}

void UserEditDialog::accept() {
    UserRole role;
    switch (ui->cb_role->currentIndex()) {
        case 0:
            role = UserRole::ADMINISTRATOR;
            break;
        case 1:
            role = UserRole::DISPATCHER;
            break;
        case 2:
            role = UserRole::SKIPPER;
            break;
    }
    bool emptyTitle = ui->et_login->text().trimmed().isEmpty();
    bool emptyPassword = ui->et_password->text().trimmed().isEmpty();
    bool lowerank = this->_user_data->edit && this->_user_data->role < role;
    if (emptyTitle || emptyPassword || lowerank) {
        QMessageBox errDlg(this);
        errDlg.setTextFormat(Qt::RichText);
        errDlg.setWindowTitle(tr("Error"));
        errDlg.setIcon(QMessageBox::Critical);
        QString message = tr("Some errors happend, while saving your note:");
        if (emptyTitle) {
            message.append("<br>- Title cannot be empty (all spaces - empty too)");
        }
        if (emptyPassword) {
            message.append("<br>- Password cannot be empty (all spaces - empty too)");
        }
        if (lowerank) {
            message.append("<br>- You cannot lower users rank");
        }
        errDlg.setText(message);
        errDlg.exec();
        return;
    }

    this->_user_data->login = ui->et_login->text().trimmed();
    this->_user_data->password = ui->et_password->text().trimmed();
    this->_user_data->role = role;

    QDialog::accept();
}
