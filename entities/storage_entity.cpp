#include "storage_entity.h"


unsigned long long storage_entity::__global_id = 0;

storage_entity::storage_entity(unsigned int capacity) : _capacity(capacity) {
    this->_id = ++storage_entity::__global_id;
}


unsigned long long storage_entity::id() {
    return this->_id;
}

unsigned int storage_entity::capacity() {
    return this->_capacity;
}

const QVector<cargo_entity> storage_entity::cargo() {
    return this->_cargo;
}
