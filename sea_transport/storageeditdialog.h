#ifndef STORAGEEDITDIALOG_H
#define STORAGEEDITDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>

#include "entities/storage_entity.h"
#include "viewmodels/cargoviewmodel.h"
#include "cargoeditdialog.h"


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class StorageEditDialog; }

/**
 * @brief Storage edit Dialog
 * 
 */
class StorageEditDialog : public QDialog {
private:
    Q_OBJECT
    //! Layout object
    Ui::StorageEditDialog *ui;

    //! Cargo ViewModel
    CargoViewModel *cvm;
    //! Storage object
    storage_entity *_storage;

public:
    /**
     * @brief Construct a new Storage Edit Dialog
     * 
     * @param parent [ignored]
     */
    explicit StorageEditDialog(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Storage Edit Dialog
     * 
     */
    ~StorageEditDialog();

    /**
     * @brief Returns storage object pointer
     * 
     * @return storage_entity* 
     */
    storage_entity* storage();
    /**
     * @brief Set storage object
     * 
     * @param ent 
     * @param edit 
     */
    void set_storage(storage_entity *ent, bool edit);

public slots:
    /**
     * @brief On new cargo add slot
     * 
     */
    void on_cargo_add();
    /**
     * @brief Dialog accept slot
     * 
     */
    void accept() Q_DECL_OVERRIDE;
};

#endif // STORAGEEDITDIALOG_H
