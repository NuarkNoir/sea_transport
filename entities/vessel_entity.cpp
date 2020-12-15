#include "vessel_entity.h"


unsigned long long vessel_entity::__global_id = 0;

vessel_entity::vessel_entity(const dpoint_entity &harbor, unsigned int capacity) : _harbor(harbor), _capacity(capacity) {
    this->_id = ++vessel_entity::__global_id;
}

unsigned long long vessel_entity::id() {
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