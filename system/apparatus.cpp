#include "apparatus.h"


apparatus *apparatus::_instance = nullptr;
const QString apparatus::filename = "data.bin";

void apparatus::open_reading_stream() {
    this->_bin_file = new QFile(apparatus::filename);
    this->_bin_file->open(QIODevice::ReadOnly);

    stream.setDevice(_bin_file);
}

void apparatus::open_writing_stream() {
    this->_bin_file = new QFile(apparatus::filename);
    this->_bin_file->open(QIODevice::WriteOnly);

    stream.setDevice(_bin_file);
}

void apparatus::close_stream() {
    stream.setDevice(nullptr);

    this->_bin_file->close();
    delete this->_bin_file;
    this->_bin_file = nullptr;
}

apparatus::apparatus() {
    this->open_reading_stream();
    this->loadGIDS();
    this->deserialize_data();
    this->close_stream();
}

apparatus::~apparatus() {
    if (this->_bin_file) {
        this->_bin_file->flush();
        this->_bin_file->close();
        delete this->_bin_file;
        this->_bin_file = nullptr;
    }
}

apparatus& apparatus::instance() {
    if (apparatus::_instance == nullptr) {
        apparatus::init();
    }

    return *apparatus::_instance;
}

bool apparatus::isFirstRun() {
    return QFile(apparatus::filename).exists();
}

void apparatus::init() {
    apparatus::_instance = new apparatus();
}

void apparatus::shutdown() {
    if (apparatus::_instance != nullptr) {
        apparatus::_instance->open_writing_stream();
        apparatus::_instance->writeGIDS();
        apparatus::_instance->serialize_data();
        apparatus::_instance->close_stream();
    }
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

}

void apparatus::deserialize_data() {

}
