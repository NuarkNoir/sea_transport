#ifndef VESSELEDITDIALOG_H
#define VESSELEDITDIALOG_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

#include "entities/vessel_entity.h"
#include "system/apparatus.h"
#include "viewmodels/cargoviewmodel.h"
#include "cargoeditdialog.h"


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class VesselEditDialog; }

/**
 * @brief Vessel edit Dialog
 * 
 */
class VesselEditDialog : public QDialog {
private:
    Q_OBJECT
    //! Layout object
    Ui::VesselEditDialog *ui;

    //! Cargo ViewModel
    CargoViewModel *cvm;
    //! Vessel entity pointer
    vessel_entity *_vessel;

public:
    /**
     * @brief Construct a new Vessel Edit Dialog
     * 
     * @param parent [ignored]
     */
    explicit VesselEditDialog(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Vessel Edit Dialog
     * 
     */
    ~VesselEditDialog();

    /**
     * @brief Get dialog's vessel
     * 
     * @return vessel_entity* 
     */
    vessel_entity* vessel();
    /**
     * @brief Set dialog vessel object
     * 
     * @param ves vessel object
     * @param edit is it edit intent
     */
    void set_vessel(vessel_entity *ves, bool edit);

public slots:
    /**
     * @brief Cargo add slot
     * 
     */
    void on_cargo_add();
    /**
     * @brief Move cargo from harbor to vessel slot 
     * 
     */
    void on_withdraw_from_harbor();
    /**
     * @brief Move cargo from vessel to harbor slot
     * 
     */
    void on_withdraw_from_vessel();
    /**
     * @brief Dialog accept slot
     * 
     */
    void accept() Q_DECL_OVERRIDE;

private:
    /**
     * @brief Correctly selects vessel's skipper
     * 
     */
    void select_proper_skipper();
    /**
     * @brief Correctly selects vessel's harbor
     * 
     */
    void select_proper_port();
};

#endif // VESSELEDITDIALOG_H
