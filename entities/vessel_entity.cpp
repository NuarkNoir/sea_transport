#include "vessel_entity.h"


entity_id vessel_entity::__global_id = 0;

vessel_entity::vessel_entity(const dpoint_entity &harbor, unsigned int capacity) : _harbor(harbor), _capacity(capacity) {
    this->_id = ++vessel_entity::__global_id;
}

entity_id vessel_entity::id() {
    return this->_id;
}

const dpoint_entity vessel_entity::harbor() {
    return this->_harbor;
}

unsigned int vessel_entity::capacity() {
    return this->_capacity;
}

const QVector<cargo_entity> vessel_entity::cargo() {
    return this->_cargo;
}

void vessel_entity::serialize(QDataStream &output) {
    output << this->_id;
    this->_harbor.serialize(output);
    output << this->_capacity << this->_cargo.size();
    for (auto item : this->_cargo) {
        item.serialize(output);
    }
}

void vessel_entity::deserialize(QDataStream &input) {
    input >> this->_id;
    this->_harbor.deserialize(input);
    int icnt;
    input >> this->_capacity >> icnt;
    this->_cargo.resize(icnt);
    for (int i = 0; i < icnt; i++) {
        this->_cargo[i].deserialize(input);
    }
}

void vessel_entity::preloadGlobalId(entity_id gid) {
    vessel_entity::__global_id = gid;
}

entity_id vessel_entity::GID() {
    return vessel_entity::__global_id;
}
