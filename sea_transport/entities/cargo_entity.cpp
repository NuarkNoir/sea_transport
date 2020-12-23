#include "cargo_entity.h"


entity_id cargo_entity::__global_id = 0;

cargo_entity::cargo_entity() {
    this->_id = ++cargo_entity::__global_id + QRandomGenerator().generate64();
}

cargo_entity::cargo_entity(const QString &title, unsigned int volume) : _title(title), _volume(volume) {
    this->_id = volume;
    auto hash = QCryptographicHash::hash(title.toLocal8Bit(), QCryptographicHash::Md5);
    for (auto bit : hash) {
        this->_id += bit;
    }
    this->_id += QRandomGenerator().generate64();
}

entity_id cargo_entity::id() const {
    return this->_id;
}

QString cargo_entity::title() const {
    return this->_title;
}

unsigned int cargo_entity::volume() const {
    return this->_volume;
}

void cargo_entity::serialize(QDataStream &output) {
    output << this->_id << this->_title << this->_volume;
}

void cargo_entity::deserialize(QDataStream &input) {
    input >> this->_id >> this->_title >> this->_volume;
}

void cargo_entity::preloadGlobalId(entity_id gid) {
    cargo_entity::__global_id = gid;
}

entity_id cargo_entity::GID() {
    return cargo_entity::__global_id;
}
