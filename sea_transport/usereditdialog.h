#ifndef USEREDITDIALOG_H
#define USEREDITDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "entities/user_entity.h"


namespace Ui {
class UserEditDialog;
}

class UserEditDialog : public QDialog {
    Q_OBJECT
    Ui::UserEditDialog *ui;

    struct user_data {
        QString login;
        QString password;
        UserRole role;
        bool edit;
    } *_user;

public:
    explicit UserEditDialog(QWidget *parent = nullptr);
    ~UserEditDialog();

    UserEditDialog::user_data* user() const;
    void set_user(user_entity* user, bool edit);


public slots:
    void accept() Q_DECL_OVERRIDE;
};

#endif // USEREDITDIALOG_H
