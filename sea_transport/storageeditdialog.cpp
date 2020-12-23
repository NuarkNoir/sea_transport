#include "storageeditdialog.h"
#include "ui_storageeditdialog.h"

StorageEditDialog::StorageEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::StorageEditDialog) {
    ui->setupUi(this);

    this->cvm = new CargoViewModel(this);
    ui->tv_cargo->setModel(this->cvm);

    connect(ui->tv_cargo->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        ui->pb_cargo_remove->setEnabled(selected.length() > 0);
    });

    connect(ui->pb_cargo_remove, &QPushButton::clicked, [this]() {
        auto sel = ui->tv_cargo->selectionModel()->selectedRows();
        if (sel.length() == 0) {
            return;
        }

        foreach (auto mIdx, sel) {
            auto oid = mIdx.data().toULongLong();
            bool success;
            this->_storage->withdraw_cargo(oid, success);
            if (!success) {
                QMessageBox::critical(this, "Error", "Cannot remove some of this cargo!");
            }
        }
    });

    connect(ui->pb_cargo_add, &QPushButton::clicked, this, &StorageEditDialog::on_cargo_add);

    connect(ui->pb_save, &QPushButton::clicked, this, &StorageEditDialog::accept);
    connect(ui->pb_discard, &QPushButton::clicked, this, &StorageEditDialog::reject);
}

StorageEditDialog::~StorageEditDialog() {
    delete ui;
}

storage_entity* StorageEditDialog::storage() {
    return this->_storage;
}

void StorageEditDialog::set_storage(storage_entity *ent, bool edit) {
    this->_storage = new storage_entity(*ent);

    if (edit) {
        ui->sb_capacity->setValue(ent->capacity());
        this->cvm->set_data(this->_storage->cargo());
    }

    ui->lab_capacity_current->setText(QString::number(this->_storage->capacity()));
}

void StorageEditDialog::on_cargo_add() {
    CargoEditDialog ced(this);
    ced.setWindowTitle("New cargo");
    if (ced.exec() != CargoEditDialog::Accepted) {
        return;
    }

    bool success;
    this->_storage->add_cargo(*ced.cargo(), success);
    if (success) {
        this->cvm->set_data(this->_storage->cargo());
        QMessageBox::information(this, "Success", "Cargo successfully put into storage");
    }
    else {
        QMessageBox::critical(this, "Error", "Not enough space to put cargo");
    }
}

void StorageEditDialog::accept() {
    int cvs = 0;
    foreach (auto c, this->_storage->cargo()) {
        cvs += c.volume();
    }
    if (cvs > ui->sb_capacity->value()) {
        QMessageBox::critical(this, "Error", "Cargo volume bigger than capacity");
        return;
    }

    this->_storage->set_capacity(ui->sb_capacity->value());

    QDialog::accept();
}
