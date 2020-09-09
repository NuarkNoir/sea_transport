#ifndef STORAGEEDITDIALOG_H
#define STORAGEEDITDIALOG_H

#include <QDialog>

namespace Ui {
class StorageEditDialog;
}

class StorageEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit StorageEditDialog(QWidget *parent = nullptr);
    ~StorageEditDialog();

private:
    Ui::StorageEditDialog *ui;
};

#endif // STORAGEEDITDIALOG_H
