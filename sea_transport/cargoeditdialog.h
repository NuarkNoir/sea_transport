#ifndef CARGOEDITDIALOG_H
#define CARGOEDITDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "entities/cargo_entity.h"

namespace Ui {
class CargoEditDialog;
}

class CargoEditDialog : public QDialog {
    Q_OBJECT
    Ui::CargoEditDialog *ui;

    cargo_entity *_cargo;

public:
    explicit CargoEditDialog(QWidget *parent = nullptr);
    ~CargoEditDialog();

    cargo_entity* cargo();

public slots:
    void accept() Q_DECL_OVERRIDE;
};

#endif // CARGOEDITDIALOG_H
