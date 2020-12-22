#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>

#include "viewmodels/usersviewmodel.h"
#include "viewmodels/vesselsviewmodel.h"
#include "viewmodels/deliverypointsviewmodel.h"

#include "entities/user_entity.h"

namespace Ui {
    class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

    user_entity user;

    UsersViewModel *uvm;
    VesselsViewModel *vvm;
    DeliveryPointsViewModel *dpvm;

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

    AdminPanel& set_user(const user_entity &user);

private slots:

private:
    Ui::AdminPanel *ui;

    void on_logout_requested();

    void on_vessel_add();
    void on_vessel_remove();

    void on_user_add();
    void on_user_remove();

    void on_delivery_point_add();
    void on_delivery_point_remove();
};

#endif // ADMINPANEL_H
