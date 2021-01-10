#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>

#include "usereditdialog.h"
#include "vesseleditdialog.h"
#include "deliverypointeditdialog.h"

#include "viewmodels/usersviewmodel.h"
#include "viewmodels/vesselsviewmodel.h"
#include "viewmodels/deliverypointsviewmodel.h"

#include "entities/user_entity.h"
#include "entities/dpoint_entity.h"


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class AdminPanel; }

/**
 * @brief Administration window
 * 
 */
class AdminPanel : public QMainWindow {
private:
    Q_OBJECT
    //! Layout object
    Ui::AdminPanel *ui;

    //! Current user object
    user_entity user;

    //! Users ViewModel
    UsersViewModel *uvm;
    //! Vessels ViewModel
    VesselsViewModel *vvm;
    //! Delivery points ViewModel
    DeliveryPointsViewModel *dpvm;

public:
    /**
     * @brief Construct a new Admin Panel
     * 
     * @param parent [ignored]
     */
    explicit AdminPanel(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Admin Panel
     * 
     */
    ~AdminPanel();

    /**
     * @brief Builder-like function, to set current user
     * 
     * @param user new current user reference
     * @return AdminPanel& 
     */
    AdminPanel& set_user(const user_entity &user);

signals:
    /**
     * @brief Then user set signal
     * 
     */
    void user_set();

private slots:
    /**
     * @brief On user set slot
     * 
     */
    void on_user_set();

private:
    /**
     * @brief Action to be called, then user pressed logout button
     * 
     */
    void on_logout_requested();

    /**
     * @brief Action to be called, whenever user wants to edit or add new vessel
     * 
     * @param edit is it creation or edit intent
     */
    void on_vessel_add_edit(bool edit);
    /**
     * @brief Action to be called, whenever user wants to remove vessel
     * 
     */
    void on_vessel_remove();

    /**
     * @brief Action to be called, whenever user wants to edit or add new user
     * 
     * @param edit is it creation or edit intent
     */
    void on_user_add_edit(bool edit);
    /**
     * @brief Action to be called, whenever user wants to remove user
     * 
     */
    void on_user_remove();

    /**
     * @brief Action to be called, whenever user wants to edit or add new delivery point
     * 
     * @param edit is it creation or edit intent
     */
    void on_delivery_point_add_edit(bool edit);
    /**
     * @brief Action to be called, whenever user wants to remove delivery point
     * 
     */
    void on_delivery_point_remove();
};

#endif // ADMINPANEL_H
