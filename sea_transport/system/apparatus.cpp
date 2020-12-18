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
    this->shutdown();
}

apparatus* apparatus::instance() {
    if (apparatus::_instance == nullptr) {
        throw std::runtime_error("System non initialized!");
    }

    return apparatus::_instance;
}

bool apparatus::isFirstRun() {
    return QFile().exists("init");
}

void apparatus::generate_empty_data() {
    this->open_stream();
    this->writeGIDS();
    this->serialize_data();
    this->close_stream();
}

const auth_system& apparatus::get_auth_subsystem() {
    return this->_auth_system;
}

const object_system& apparatus::get_object_subsystem() {
    return this->_object_system;
}

void apparatus::init() {
    apparatus::_instance = new apparatus();

    apparatus::instance()->open_stream();
    apparatus::instance()->loadGIDS();
    apparatus::instance()->deserialize_data();
    apparatus::instance()->close_stream();
}

void apparatus::shutdown() {
    apparatus::instance()->open_stream();
    apparatus::instance()->writeGIDS();
    apparatus::instance()->serialize_data();
    apparatus::instance()->close_stream();
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
    this->_auth_system.init(this->stream);
    this->_object_system.init(this->stream);
}

void apparatus::deserialize_data() {
    QFile("init").open(QIODevice::ReadWrite);
    this->_auth_system.shutdown(this->stream);
    this->_object_system.shutdown(this->stream);
}
