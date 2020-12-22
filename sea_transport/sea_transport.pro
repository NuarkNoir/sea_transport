QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpanel.cpp \
    authwindow.cpp \
    cargoeditdialog.cpp \
    deliverypointeditdialog.cpp \
    entities/cargo_entity.cpp \
    entities/dpoint_entity.cpp \
    entities/storage_entity.cpp \
    entities/user_entity.cpp \
    entities/vessel_entity.cpp \
    main.cpp \
    storageeditdialog.cpp \
    system/apparatus.cpp \
    system/auth_system.cpp \
    system/object_system.cpp \
    usereditdialog.cpp \
    vesseleditdialog.cpp \
    viewmodels/deliverypointsviewmodel.cpp \
    viewmodels/usersviewmodel.cpp \
    viewmodels/vesselsviewmodel.cpp

HEADERS += \
    adminpanel.h \
    authwindow.h \
    cargoeditdialog.h \
    deliverypointeditdialog.h \
    entities/IEntity.h \
    entities/ISerializable.h \
    entities/cargo_entity.h \
    entities/dpoint_entity.h \
    entities/storage_entity.h \
    entities/user_entity.h \
    entities/vessel_entity.h \
    storageeditdialog.h \
    system/apparatus.h \
    system/auth_system.h \
    system/object_system.h \
    usereditdialog.h \
    vesseleditdialog.h \
    viewmodels/deliverypointsviewmodel.h \
    viewmodels/usersviewmodel.h \
    viewmodels/vesselsviewmodel.h

FORMS += \
    adminpanel.ui \
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
