#include "authwindow.h"

#include "system/apparatus.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    apparatus::init();

    AuthWindow w(nullptr);
    w.show();

    QObject::connect(&a, &QApplication::aboutToQuit, []() {
        apparatus::shutdown();
        if (apparatus::isFirstRun()) {
            apparatus::generate_lock_file();
        }
    });
    return a.exec();
}
