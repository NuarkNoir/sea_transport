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


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class DeliveryPointEditDialog; }

/**
 * @brief Delivery point edit Dialog
 * 
 */
class DeliveryPointEditDialog : public QDialog {
private:
    Q_OBJECT
    //! Layout object
    Ui::DeliveryPointEditDialog *ui;

    //! ViewModel for DP's storages
    QStringListModel *svm;
    //! Delivery point object
    dpoint_entity *_dp;

public:
    /**
     * @brief Construct a new Delivery Point Edit Dialog
     * 
     * @param parent [ignored]
     */
    explicit DeliveryPointEditDialog(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Delivery Point Edit Dialog
     * 
     */
    ~DeliveryPointEditDialog();

    /**
     * @brief Returns delivery point object pointer
     * 
     * @return dpoint_entity* 
     */
    dpoint_entity* dpoint() const;
    /**
     * @brief Set delivery point object
     * 
     * @param dpoint 
     * @param edit 
     */
    void set_dpoint(dpoint_entity* dpoint, bool edit);

public slots:
    /**
     * @brief On new storage add slot
     * 
     * @param edit 
     */
    void on_storage_edit_add(bool edit);

    /**
     * @brief Dialog accept slot
     * 
     */
    void accept() Q_DECL_OVERRIDE;

private:
    /**
     * @brief Updates storages list
     * 
     */
    void update_list();
};

#endif // DELIVERYPOINTEDITDIALOG_H
