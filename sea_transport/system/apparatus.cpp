#include "apparatus.h"


apparatus *apparatus::_instance = nullptr;
const QString apparatus::filename = "data.bin";

void apparatus::open_stream() {
    this->_bin_file = new QFile(apparatus::filename);
    this->_bin_file->open(QIODevice::ReadWrite);

    stream.setDevice(_bin_file);
}

void apparatus::close_stream() {
    stream.setDevice(nullptr);

    this->_bin_file->close();
    delete this->_bin_file;
    this->_bin_file = nullptr;
}

apparatus::apparatus() {

}

apparatus::~apparatus() {

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

bool apparatus::isFirstRun() {
    return !QFile().exists("lock");
}

auth_system& apparatus::get_auth_subsystem() {
    return this->_auth_system;
}

object_system& apparatus::get_object_subsystem() {
    return this->_object_system;
}

void apparatus::init() {
    apparatus::_instance = new apparatus();

    apparatus::_instance->open_stream();
    apparatus::_instance->loadGIDS();
    apparatus::_instance->deserialize_data();
}

void apparatus::shutdown() {
    apparatus::_instance->writeGIDS();
    apparatus::_instance->serialize_data();
    apparatus::_instance->close_stream();
    delete apparatus::_instance;
}

void apparatus::writeGIDS() {
    entity_id vgid = vessel_entity::GID();
    entity_id sgid = storage_entity::GID();
    this->stream << vgid << sgid;
}

void apparatus::loadGIDS() {
    entity_id vgid, sgid;
    this->stream >> vgid >> sgid;
    vessel_entity::preloadGlobalId(vgid);
    storage_entity::preloadGlobalId(sgid);
}

void apparatus::serialize_data() {
    this->_auth_system.serialize_data(this->stream);
    this->_object_system.serialize_data(this->stream);
}

void apparatus::deserialize_data() {
    this->_auth_system.deserialize_data(this->stream);
    this->_object_system.deserialize_data(this->stream);
}
