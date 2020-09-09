#ifndef DELIVERYPOINTEDITDIALOG_H
#define DELIVERYPOINTEDITDIALOG_H

#include <QDialog>

namespace Ui {
class DeliveryPointEditDialog;
}

class DeliveryPointEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DeliveryPointEditDialog(QWidget *parent = nullptr);
    ~DeliveryPointEditDialog();

private:
    Ui::DeliveryPointEditDialog *ui;
};

#endif // DELIVERYPOINTEDITDIALOG_H
