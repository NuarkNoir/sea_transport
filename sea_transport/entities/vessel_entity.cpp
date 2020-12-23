#include "vessel_entity.h"


entity_id vessel_entity::__global_id = 0;

vessel_entity::vessel_entity() {
    this->_id = ++vessel_entity::__global_id + QRandomGenerator().generate64();
}

vessel_entity::vessel_entity(QString skipper, entity_id harbor_id, unsigned int capacity) : _skipper(skipper), _harbor_id(harbor_id), _capacity(capacity) {
    this->_id = ++vessel_entity::__global_id + harbor_id + capacity + QRandomGenerator().generate64();
}

entity_id vessel_entity::id() const {
    return this->_id;
}

QString vessel_entity::skipper() const {
    return this->_skipper;
}

void vessel_entity::set_skipper(const QString &new_skipper) {
    this->_skipper = new_skipper;
}

entity_id vessel_entity::harbor() const {
    return this->_harbor_id;
}

void vessel_entity::set_harbor(entity_id new_harbor) {
    this->_harbor_id = new_harbor;
}

unsigned int vessel_entity::capacity() const {
    return this->_capacity;
}

void vessel_entity::set_capacity(unsigned int new_capacity) {
    this->_capacity = new_capacity;
}

const QVector<cargo_entity> vessel_entity::cargo() {
    return this->_cargo;
}

void vessel_entity::add_cargo(cargo_entity object, bool &success) {
    success = ((int)this->_capacity - (int)object.volume()) >= 0;
    if (success) {
        this->_cargo.push_back(object);
        this->_capacity -= object.volume();
    }
}

cargo_entity vessel_entity::get_cargo(entity_id oid, bool &found) {
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

void vessel_entity::withdraw_cargo(entity_id oid, bool &success) {
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

void vessel_entity::serialize(QDataStream &output) {
    output << this->_id << this->_skipper << this->_harbor_id;
    output << this->_capacity << this->_cargo.size();
    for (auto item : this->_cargo) {
        item.serialize(output);
    }
}

void vessel_entity::deserialize(QDataStream &input) {
    input >> this->_id >> this->_skipper  >> this->_harbor_id;
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
