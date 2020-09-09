#ifndef USEREDITDIALOG_H
#define USEREDITDIALOG_H

#include <QDialog>

namespace Ui {
class UserEditDialog;
}

class UserEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserEditDialog(QWidget *parent = nullptr);
    ~UserEditDialog();

private:
    Ui::UserEditDialog *ui;
};

#endif // USEREDITDIALOG_H
