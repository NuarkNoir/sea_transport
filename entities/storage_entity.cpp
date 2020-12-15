#include "storage_entity.h"


entity_id storage_entity::__global_id = 0;

storage_entity::storage_entity(unsigned int capacity) : _capacity(capacity) {
    this->_id = ++storage_entity::__global_id;
}


entity_id storage_entity::id() {
    return this->_id;
}

unsigned int storage_entity::capacity() {
    return this->_capacity;
}

const QVector<cargo_entity> storage_entity::cargo() {
    return this->_cargo;
}

void storage_entity::add_cargo(cargo_entity object, bool &success) {
    success = ((int)this->_capacity - (int)object.volume()) > 0;
    if (success) {
        this->_cargo.push_back(object);
        this->_capacity -= object.volume();
    }
}

cargo_entity storage_entity::get_cargo(entity_id oid, bool &found) {
    cargo_entity ent;
    found = false;

    auto vit = this->_cargo.begin();
    for (; vit != this->_cargo.end(); vit++) {
        if ((*vit).id() == oid) {
            ent = *vit;
            found = true;
            break;
        }
    }
    return ent;
}

void storage_entity::withdraw_cargo(entity_id oid, bool &success) {
    success = false;
    auto vit = this->_cargo.begin();
    for (; vit != this->_cargo.end(); vit++) {
        if ((*vit).id() == oid) {
            this->_capacity += (*vit).volume();
            this->_cargo.erase(vit);
            success = true;
            break;
        }
    }
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

void storage_entity::preloadGlobalId(entity_id gid) {
    storage_entity::__global_id = gid;
}

entity_id storage_entity::GID() {
    return storage_entity::__global_id;
}
