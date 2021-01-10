#ifndef CARGOEDITDIALOG_H
#define CARGOEDITDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "entities/cargo_entity.h"


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class CargoEditDialog; }

/**
 * @brief Cargo edit Dialog
 * 
 */
class CargoEditDialog : public QDialog {
private:
    Q_OBJECT
    //! Layout object
    Ui::CargoEditDialog *ui;

    //! Cargo entity object
    cargo_entity *_cargo;

public:
    /**
     * @brief Construct a new Cargo Edit Dialog
     * 
     * @param parent [ignored]
     */
    explicit CargoEditDialog(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Cargo Edit Dialog
     * 
     */
    ~CargoEditDialog();

    /**
     * @brief Returns cargo object pointer
     * 
     * @return cargo_entity* 
     */
    cargo_entity* cargo();

public slots:
    /**
     * @brief Dialog accept slot
     * 
     */
    void accept() Q_DECL_OVERRIDE;
};

#endif // CARGOEDITDIALOG_H
