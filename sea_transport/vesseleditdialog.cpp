#include "vesseleditdialog.h"
#include "ui_vesseleditdialog.h"

VesselEditDialog::VesselEditDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::VesselEditDialog)
{
    ui->setupUi(this);
}

VesselEditDialog::~VesselEditDialog()
{
    delete ui;
}
