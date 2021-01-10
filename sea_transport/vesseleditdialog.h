#ifndef VESSELEDITDIALOG_H
#define VESSELEDITDIALOG_H

#include <QDialog>
#include <QInputDialog>
#include <QMessageBox>

#include "entities/vessel_entity.h"
#include "system/apparatus.h"
#include "viewmodels/cargoviewmodel.h"
#include "cargoeditdialog.h"


namespace Ui { class VesselEditDialog; }

class VesselEditDialog : public QDialog {
private:
    Q_OBJECT
    Ui::VesselEditDialog *ui;

    CargoViewModel *cvm;
    vessel_entity *_vessel;

public:
    explicit VesselEditDialog(QWidget *parent = nullptr);
    ~VesselEditDialog();

    vessel_entity* vessel();
    void set_vessel(vessel_entity *ves, bool edit);

public slots:
    void on_cargo_add();
    void on_withdraw_from_harbor();
    void on_withdraw_from_vessel();
    void accept() Q_DECL_OVERRIDE;

private:
    void select_proper_skipper();
    void select_proper_port();
};

#endif // VESSELEDITDIALOG_H
