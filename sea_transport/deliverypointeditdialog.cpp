#include "deliverypointeditdialog.h"
#include "ui_deliverypointeditdialog.h"


DeliveryPointEditDialog::DeliveryPointEditDialog(QWidget *parent) : QDialog(parent), ui(new Ui::DeliveryPointEditDialog) {
    ui->setupUi(this);

    this->svm = new QStringListModel(this);
    ui->lv_storages->setModel(this->svm);

    connect(ui->lv_storages->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection &selected) {
        ui->pb_storage_remove->setEnabled(selected.length() > 0);
        ui->pb_storage_edit->setEnabled(selected.length() == 1);
    });

    connect(ui->pb_storage_remove, &QPushButton::clicked, [this]() {
        auto sel = ui->lv_storages->selectionModel()->selectedRows();
        if (sel.length() == 0) {
            return;
        }

        foreach (auto mIdx, sel) {
            auto cuid = mIdx.data().toString().toULongLong();
            auto st = this->_dp->storages();

            for (int i = 0; i < st.length(); i++) {
                if (st[i].id() == cuid) {
                    st.removeAt(i);
                    break;
                }
            }

            this->_dp->set_storages(st);
        }
        this->update_list();
    });

    connect(ui->pb_storage_edit, &QPushButton::clicked, [this]() {
        this->on_storage_edit_add(true);
    });

    connect(ui->pb_storage_add, &QPushButton::clicked, [this]() {
        this->on_storage_edit_add(false);
    });

    connect(ui->pb_save, &QPushButton::clicked, this, &DeliveryPointEditDialog::accept);
    connect(ui->pb_discard, &QPushButton::clicked, this, &DeliveryPointEditDialog::reject);
}

DeliveryPointEditDialog::~DeliveryPointEditDialog() {
    delete ui;
}

void DeliveryPointEditDialog::update_list() {
    QStringList slist;
    foreach (auto storage, this->_dp->storages()) {
        slist << QString::number(storage.id());
    }
    this->svm->setStringList(slist);
}

dpoint_entity* DeliveryPointEditDialog::dpoint() const {
    return this->_dp;
}

void DeliveryPointEditDialog::on_storage_edit_add(bool edit) {
    auto selected = ui->lv_storages->selectionModel()->selectedRows();
    if (edit && selected.length() != 1) {
        return;
    }

    storage_entity stor;
    if (edit) {
        int idx = selected[0].row();
        stor = this->_dp->storages()[idx];
        this->_dp->remove_storage(stor.id());
    }

    StorageEditDialog sed(this);
    sed.setWindowTitle(edit? "Edit storage" : "New storage");
    sed.set_storage(&stor, edit);
    if (sed.exec() != StorageEditDialog::Accepted) {
        return;
    }

    auto n_storage = sed.storage();
    if (edit) {
        this->_dp->remove_storage(stor.id());
    }
    this->_dp->add_storage(*n_storage);

    this->update_list();
}

void DeliveryPointEditDialog::set_dpoint(dpoint_entity* dpoint, bool edit) {
    this->_dp = new dpoint_entity(*dpoint);

    if (edit) {
        ui->et_title->setText(dpoint->title());
        this->update_list();
    }
}

void DeliveryPointEditDialog::accept() {
    bool emptyTitle = ui->et_title->text().trimmed().isEmpty();
    if (emptyTitle) {;
        QString message = "Some errors happend, while saving your note:"
                          "<br>- Title cannot be empty (all spaces - empty too)";
        QMessageBox::critical(this, "Error", message);
        return;
    }

    this->_dp->set_title(ui->et_title->text().trimmed());

    QDialog::accept();
}
