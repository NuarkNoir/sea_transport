#ifndef VESSELEDITDIALOG_H
#define VESSELEDITDIALOG_H

#include <QDialog>

namespace Ui {
class VesselEditDialog;
}

class VesselEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit VesselEditDialog(QWidget *parent = nullptr);
    ~VesselEditDialog();

private:
    Ui::VesselEditDialog *ui;
};

#endif // VESSELEDITDIALOG_H
