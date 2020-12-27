#include "skipperpanel.h"
#include "ui_skipperpanel.h"

SkipperPanel::SkipperPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SkipperPanel)
{
    ui->setupUi(this);
}

SkipperPanel::~SkipperPanel()
{
    delete ui;
}
