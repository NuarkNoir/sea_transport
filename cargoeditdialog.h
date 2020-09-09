#ifndef CARGOEDITDIALOG_H
#define CARGOEDITDIALOG_H

#include <QDialog>

namespace Ui {
class CargoEditDialog;
}

class CargoEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CargoEditDialog(QWidget *parent = nullptr);
    ~CargoEditDialog();

private:
    Ui::CargoEditDialog *ui;
};

#endif // CARGOEDITDIALOG_H
