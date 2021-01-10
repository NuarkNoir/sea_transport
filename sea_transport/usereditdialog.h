#ifndef USEREDITDIALOG_H
#define USEREDITDIALOG_H

#include <QDialog>
#include <QMessageBox>

#include "entities/user_entity.h"


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class UserEditDialog; }

/**
 * @brief User data struct for new user's data to be moved
 * 
 */
struct user_data_struct {
    //! User's login
    QString login;
    //! User's password
    QString password;
    //! User's account role
    UserRole role;
    //! Are we editing user?
    bool edit;
};

/**
 * @brief User edit Dialog
 * 
 */
class UserEditDialog : public QDialog {
private:
    Q_OBJECT
    //! Layout object
    Ui::UserEditDialog *ui;

    //! User data structure pointer
    user_data_struct *_user_data;

public:
    /**
     * @brief Construct a new User Edit Dialog
     * 
     * @param parent [ignored]
     */
    explicit UserEditDialog(QWidget *parent = nullptr);
    /**
     * @brief Destroy the User Edit Dialog
     * 
     */
    ~UserEditDialog();

    /**
     * @brief Returns user data pointer
     * 
     * @return user_data_struct* 
     */
    user_data_struct* user_data() const;
    /**
     * @brief Set user object
     * 
     * @param user 
     * @param edit 
     */
    void set_user(user_entity* user, bool edit);

public slots:
    /**
     * @brief Dialog accept slot
     * 
     */
    void accept() Q_DECL_OVERRIDE;
};

#endif // USEREDITDIALOG_H
