QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authwindow.cpp \
    cargoeditdialog.cpp \
    deliverypointeditdialog.cpp \
    entities/cargo_entity.cpp \
    main.cpp \
    storageeditdialog.cpp \
    usereditdialog.cpp \
    vesseleditdialog.cpp

HEADERS += \
    authwindow.h \
    cargoeditdialog.h \
    deliverypointeditdialog.h \
    entities/cargo_entity.h \
    storageeditdialog.h \
    usereditdialog.h \
    vesseleditdialog.h

FORMS += \
    authwindow.ui \
    cargoeditdialog.ui \
    deliverypointeditdialog.ui \
    storageeditdialog.ui \
    usereditdialog.ui \
    vesseleditdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
