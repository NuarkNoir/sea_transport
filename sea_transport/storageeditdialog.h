#ifndef STORAGEEDITDIALOG_H
#define STORAGEEDITDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>

#include "entities/storage_entity.h"
#include "viewmodels/cargoviewmodel.h"
#include "cargoeditdialog.h"


namespace Ui {
class StorageEditDialog;
}

class StorageEditDialog : public QDialog {
    Q_OBJECT
    Ui::StorageEditDialog *ui;

    CargoViewModel *cvm;
    storage_entity *_storage;

public:
    explicit StorageEditDialog(QWidget *parent = nullptr);
    ~StorageEditDialog();

    storage_entity* storage();
    void set_storage(storage_entity *ent, bool edit);

public slots:
    void on_cargo_add();
    void accept() Q_DECL_OVERRIDE;
};

#endif // STORAGEEDITDIALOG_H
