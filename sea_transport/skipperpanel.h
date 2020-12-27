#ifndef SKIPPERPANEL_H
#define SKIPPERPANEL_H

#include <QMainWindow>
#include <QMessageBox>
#include <QVector>

#include "system/apparatus.h"
#include "viewmodels/cargoviewmodel.h"
#include "entities/user_entity.h"
#include "entities/vessel_entity.h"

namespace Ui {
    class SkipperPanel;
}

class SkipperPanel : public QMainWindow {
    Q_OBJECT

    user_entity user;

    CargoViewModel *cvm;

public:
    explicit SkipperPanel(QWidget *parent = nullptr);
    ~SkipperPanel();

    SkipperPanel& set_user(const user_entity &user);

signals:
    void user_set();

private slots:
    void on_user_set();

private:
    Ui::SkipperPanel *ui;

    void on_logout_requested();
};

#endif // SKIPPERPANEL_H
