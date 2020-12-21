#include "authwindow.h"

#include "system/apparatus.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    bool fr = apparatus::isFirstRun();

    apparatus::init();
    AuthWindow w(nullptr, fr);
    w.show();
    int ecode = a.exec();
    apparatus::shutdown();

    return ecode;
}
