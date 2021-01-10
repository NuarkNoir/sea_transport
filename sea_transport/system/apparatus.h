#ifndef APPARATUS_H
#define APPARATUS_H

#include "auth_system.h"
#include "object_system.h"

#include "../entities/vessel_entity.h"
#include "../entities/storage_entity.h"

#include <QString>
#include <QFile>
#include <QDataStream>


class apparatus {
private:
    static apparatus *_instance;
    static const QString filename;

    auth_system* _auth_system;
    object_system* _object_system;

public:
    explicit apparatus();
    ~apparatus();

    auth_system* get_auth_subsystem();
    object_system* get_object_subsystem();

    void save();
    void load();

    static bool is_first_run();
    static void generate_lock_file();
    static apparatus* instance();
    static void init();
    static void shutdown();
};

#endif // APPARATUS_H
