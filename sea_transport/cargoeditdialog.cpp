#include "cargoeditdialog.h"
#include "ui_cargoeditdialog.h"

CargoEditDialog::CargoEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::CargoEditDialog) {
    ui->setupUi(this);
}

CargoEditDialog::~CargoEditDialog() {
    delete ui;
}

cargo_entity* CargoEditDialog::cargo() {
    return this->_cargo;
}

void CargoEditDialog::accept() {
    bool emptyTitle = ui->et_title->text().trimmed().isEmpty();
    if (emptyTitle) {
        QMessageBox::critical(this, "Error", "Title cannot be empty");
        return;
    }

    this->_cargo = new cargo_entity(ui->et_title->text().trimmed(), ui->sb_volume->value());

    QDialog::accept();
}
