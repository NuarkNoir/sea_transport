#ifndef SKIPPERPANEL_H
#define SKIPPERPANEL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>

#include "system/apparatus.h"
#include "viewmodels/cargoviewmodel.h"
#include "entities/user_entity.h"
#include "entities/vessel_entity.h"


/**
 * @brief Namespace for UI layout MOC to be generated
 * 
 */
namespace Ui { class SkipperPanel; }

/**
 * @brief Skipper info panel
 * 
 */
class SkipperPanel : public QMainWindow {
private:
    Q_OBJECT
    //! Layout object
    Ui::SkipperPanel *ui;

    //! User entity object
    user_entity user;
    //! Cargo ViewModel
    CargoViewModel *cvm;

public:
    /**
     * @brief Construct a new Skipper Panel
     * 
     * @param parent [ignored]
     */
    explicit SkipperPanel(QWidget *parent = nullptr);
    /**
     * @brief Destroy the Skipper Panel
     * 
     */
    ~SkipperPanel();

    /**
     * @brief Set user object
     * 
     * @param user 
     * @return SkipperPanel& 
     */
    SkipperPanel& set_user(const user_entity &user);

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
};

#endif // SKIPPERPANEL_H
