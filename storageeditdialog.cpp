#include "storageeditdialog.h"
#include "ui_storageeditdialog.h"

StorageEditDialog::StorageEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StorageEditDialog)
{
    ui->setupUi(this);
}

StorageEditDialog::~StorageEditDialog()
{
    delete ui;
}
