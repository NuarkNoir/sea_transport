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


namespace Ui { class AdminPanel; }

class AdminPanel : public QMainWindow {
private:
    Q_OBJECT

    Ui::AdminPanel *ui;

    user_entity user;

    UsersViewModel *uvm;
    VesselsViewModel *vvm;
    DeliveryPointsViewModel *dpvm;

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

    AdminPanel& set_user(const user_entity &user);

signals:
    void user_set();

private slots:
    void on_user_set();

private:
    void on_logout_requested();

    void on_vessel_add_edit(bool edit);
    void on_vessel_remove();

    void on_user_add_edit(bool edit);
    void on_user_remove();

    void on_delivery_point_add_edit(bool edit);
    void on_delivery_point_remove();
};

#endif // ADMINPANEL_H
