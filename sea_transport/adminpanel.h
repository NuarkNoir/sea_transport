#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>

#include "entities/user_entity.h"

namespace Ui {
    class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

    user_entity user;

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();

    AdminPanel& set_user(const user_entity &user);

private slots:
    void on_logout_requested();

    void on_vessel_add();
    void on_vessel_remove();

    void on_user_add();
    void on_user_remove();

    void on_storage_add();
    void on_storage_remove();

    void on_delivery_point_add();
    void on_delivery_point_remove();

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
