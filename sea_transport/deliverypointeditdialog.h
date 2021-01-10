#ifndef DELIVERYPOINTEDITDIALOG_H
#define DELIVERYPOINTEDITDIALOG_H

#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QStringList>
#include <QStringListModel>

#include "entities/dpoint_entity.h"
#include "system/apparatus.h"
#include "storageeditdialog.h"


namespace Ui { class DeliveryPointEditDialog; }

class DeliveryPointEditDialog : public QDialog {
private:
    Q_OBJECT
    Ui::DeliveryPointEditDialog *ui;

    QStringListModel *svm;
    dpoint_entity *_dp;

public:
    explicit DeliveryPointEditDialog(QWidget *parent = nullptr);
    ~DeliveryPointEditDialog();

    dpoint_entity* dpoint() const;
    void set_dpoint(dpoint_entity* dpoint, bool edit);

public slots:
    void on_storage_edit_add(bool edit);

    void accept() Q_DECL_OVERRIDE;

private:
    void update_list();
};

#endif // DELIVERYPOINTEDITDIALOG_H
