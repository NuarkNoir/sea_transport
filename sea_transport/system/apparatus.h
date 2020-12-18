#ifndef APPARATUS_H
#define APPARATUS_H

#include "auth_system.h"
#include "object_system.h"

#include "../entities/vessel_entity.h"
#include "../entities/storage_entity.h"

#include <QString>
#include <QFile>
#include <QDataStream>


class apparatus
{
private:
    static apparatus *_instance;
    static const QString filename;

    QFile *_bin_file;
    QDataStream stream;

    auth_system _auth_system;
    object_system _object_system;

    void open_stream();
    void close_stream();

    void writeGIDS();
    void loadGIDS();

    void serialize_data();
    void deserialize_data();

public:
    apparatus();
    ~apparatus();

    bool isFirstRun();
    void generate_empty_data();
    const auth_system& get_auth_subsystem();
    const object_system& get_object_subsystem();

    static apparatus* instance();
    static void init();
    static void shutdown();
};

#endif // APPARATUS_H
