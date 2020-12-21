#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include <system/apparatus.h>

#include "adminpanel.h"

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class AuthWindow;
}

class AuthWindow : public QMainWindow
{
    Q_OBJECT
    bool firstRun;

public:
    explicit AuthWindow(QWidget *parent = nullptr, bool fr = false);
    ~AuthWindow();


private slots:
    void on_auth_requested();

private:
    Ui::AuthWindow *ui;
};

#endif // AUTHWINDOW_H
