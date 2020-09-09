#include "cargoeditdialog.h"
#include "ui_cargoeditdialog.h"

CargoEditDialog::CargoEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CargoEditDialog)
{
    ui->setupUi(this);
}

CargoEditDialog::~CargoEditDialog()
{
    delete ui;
}
