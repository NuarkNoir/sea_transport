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

void storage_entity::serialize(QDataStream &output) {
    output << this->_id << this->_capacity << this->_cargo.size();
    for (auto item : this->_cargo) {
        item.serialize(output);
    }
}

void storage_entity::deserialize(QDataStream &input) {
    int icnt;
    input >> this->_id >> this->_capacity >> icnt;
    this->_cargo.resize(icnt);
    for (int i = 0; i < icnt; i++) {
        this->_cargo[i].deserialize(input);
    }
}
