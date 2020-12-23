#ifndef USEREDITDIALOG_H
#define USEREDITDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "entities/user_entity.h"


namespace Ui {
class UserEditDialog;
}

struct user_data_struct {
    QString login;
    QString password;
    UserRole role;
    bool edit;
};

class UserEditDialog : public QDialog {
    Q_OBJECT
    Ui::UserEditDialog *ui;

    user_data_struct *_user_data;

public:
    explicit UserEditDialog(QWidget *parent = nullptr);
    ~UserEditDialog();

    user_data_struct* user_data() const;
    void set_user(user_entity* user, bool edit);

public slots:
    void accept() Q_DECL_OVERRIDE;
};

#endif // USEREDITDIALOG_H
