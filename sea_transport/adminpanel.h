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

private:
    Ui::AdminPanel *ui;
};

#endif // ADMINPANEL_H
