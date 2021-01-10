#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include "system/apparatus.h"

#include "adminpanel.h"
#include "skipperpanel.h"

#include <QMainWindow>
#include <QMessageBox>


namespace Ui { class AuthWindow; }

class AuthWindow : public QMainWindow {
private:
    Q_OBJECT

    Ui::AuthWindow *ui;

public:
    explicit AuthWindow(QWidget *parent = nullptr);
    ~AuthWindow();

private:
    void on_auth_requested();
};

#endif // AUTHWINDOW_H
