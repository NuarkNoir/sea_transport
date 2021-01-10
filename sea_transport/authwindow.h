#ifndef AUTHWINDOW_H
#define AUTHWINDOW_H

#include "system/apparatus.h"

#include "adminpanel.h"
#include "skipperpanel.h"

#include <QMainWindow>
#include <QMessageBox>


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class AuthWindow; }

/**
 * @brief Auth window
 * 
 */
class AuthWindow : public QMainWindow {
private:
    Q_OBJECT
    //! Layout object
    Ui::AuthWindow *ui;

public:
    /**
     * @brief Construct a new Auth window
     * 
     * @param parent [ignored]
     */
    explicit AuthWindow(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Auth window
     * 
     */
    ~AuthWindow();

private:
    /**
     * @brief Action to be called, then user pressed login button
     * 
     */
    void on_auth_requested();
};

#endif // AUTHWINDOW_H
