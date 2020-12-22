#include "apparatus.h"


apparatus *apparatus::_instance = nullptr;
const QString apparatus::filename = "data.bin";

apparatus::apparatus() {
    this->_auth_system = new auth_system();
    this->_object_system = new object_system();
}

apparatus::~apparatus() {
    this->save();
    delete this->_auth_system;
    delete this->_object_system;
}

void apparatus::generate_lock_file() {
    QFile init("lock");
    init.open(QIODevice::ReadWrite);
    init.write("lock");
    init.close();
}

apparatus* apparatus::instance() {
    if (apparatus::_instance == nullptr) {
        throw std::runtime_error("System non initialized!");
    }

    return apparatus::_instance;
}

void apparatus::save() {
    if (_instance == nullptr) {
        return;
    }
    QFile f(apparatus::filename);
    f.open(QIODevice::WriteOnly);
    QDataStream stream(&f);

    // saving GIDs
    entity_id vgid = vessel_entity::GID();
    entity_id sgid = storage_entity::GID();
    stream << vgid << sgid;

    // serializing data
    this->_auth_system->serialize_data(&stream);
    this->_object_system->serialize_data(&stream);

    f.close();
}

void apparatus::load() {
    if (_instance == nullptr) {
        throw std::runtime_error("HOW DU FUCK INSTANCE IS NULL????");
    }
    QFile f(apparatus::filename);
    f.open(QIODevice::ReadOnly);
    QDataStream stream(&f);

    // loading GIDs
    entity_id vgid, sgid;
    stream >> vgid >> sgid;
    vessel_entity::preloadGlobalId(vgid);
    storage_entity::preloadGlobalId(sgid);

    // deserializing data
    this->_auth_system->deserialize_data(&stream);
    this->_object_system->deserialize_data(&stream);

    f.close();
}

bool apparatus::isFirstRun() {
    return !QFile().exists("lock");
}

auth_system* apparatus::get_auth_subsystem() {
    return this->_auth_system;
}

object_system* apparatus::get_object_subsystem() {
    return this->_object_system;
}

void apparatus::init() {
    if (apparatus::_instance != nullptr) {
        throw std::runtime_error("System already initialized!");
    }

    bool fr = apparatus::isFirstRun();
    apparatus::_instance = new apparatus();

    if (fr) {
        if (!QFile().exists(apparatus::filename)) {
            QFile init(apparatus::filename);
            init.open(QIODevice::ReadWrite);
            init.close();
        }
        apparatus::_instance->save();
    }

    apparatus::_instance->load();
}

void apparatus::shutdown() {
    delete apparatus::_instance;
}
