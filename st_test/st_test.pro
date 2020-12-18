QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  tst_st_test.cpp \
            ../sea_transport/entities/cargo_entity.cpp \
            ../sea_transport/entities/storage_entity.cpp \
            ../sea_transport/entities/dpoint_entity.cpp \
            ../sea_transport/entities/vessel_entity.cpp \
            ../sea_transport/entities/user_entity.cpp \
            ../sea_transport/system/auth_system.cpp \
            ../sea_transport/system/object_system.cpp \
            ../sea_transport/system/apparatus.cpp

HEADERS +=  \
            ../sea_transport/entities/ISerializable.h \
            ../sea_transport/entities/IEntity.h \
            ../sea_transport/entities/cargo_entity.h \
            ../sea_transport/entities/storage_entity.h \
            ../sea_transport/entities/dpoint_entity.h \
            ../sea_transport/entities/vessel_entity.h \
            ../sea_transport/entities/user_entity.h \
            ../sea_transport/system/auth_system.h \
            ../sea_transport/system/object_system.h \
            ../sea_transport/system/apparatus.h
