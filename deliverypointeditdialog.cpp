#include "deliverypointeditdialog.h"
#include "ui_deliverypointeditdialog.h"

DeliveryPointEditDialog::DeliveryPointEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeliveryPointEditDialog)
{
    ui->setupUi(this);
}

DeliveryPointEditDialog::~DeliveryPointEditDialog()
{
    delete ui;
}
