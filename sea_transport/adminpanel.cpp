#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) : QMainWindow(parent), ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
}

AdminPanel::~AdminPanel() {
    delete ui;
}

AdminPanel& AdminPanel::set_user(const user_entity &user) {
    this->user = user;
    return *this;
}
