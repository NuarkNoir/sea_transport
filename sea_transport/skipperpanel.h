#ifndef SKIPPERPANEL_H
#define SKIPPERPANEL_H

#include <QMainWindow>

namespace Ui {
    class SkipperPanel;
}

class SkipperPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit SkipperPanel(QWidget *parent = nullptr);
    ~SkipperPanel();

private:
    Ui::SkipperPanel *ui;
};

#endif // SKIPPERPANEL_H
