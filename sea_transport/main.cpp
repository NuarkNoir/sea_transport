#include "authwindow.h"
#include "system/apparatus.h"

#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    apparatus::init();

    AuthWindow w(nullptr);
    w.show();

    QObject::connect(&a, &QApplication::aboutToQuit, []() {
        apparatus::instance()->save();
        if (apparatus::is_first_run()
                && apparatus::instance()->get_auth_subsystem()->users().length() > 0) {
            apparatus::generate_lock_file();
        }
    });
    return a.exec();
}
