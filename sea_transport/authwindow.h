#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include "system/apparatus.h"

#include "adminpanel.h"

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

private:
    Ui::AuthWindow *ui;

    void on_auth_requested();
};

#endif // AUTHWINDOW_H
