#include "usereditdialog.h"
#include "ui_usereditdialog.h"

UserEditDialog::UserEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserEditDialog)
{
    ui->setupUi(this);
}

UserEditDialog::~UserEditDialog()
{
    delete ui;
}
