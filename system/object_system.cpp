#include "object_system.h"


const dpoint_entity* object_system::get_dpoint(entity_id oid, bool &success) {
    dpoint_entity *out = nullptr;

    success = false;
    for (dpoint_entity &item : this->_dpoints) {
        if (item.id() == oid) {
            success = true;
            out = &item;
            break;
        }
    }

    return out;
}

bool object_system::remove_dpoint(entity_id oid) {
    auto vit = this->_dpoints.begin();
    for (; vit != this->_dpoints.end(); vit++) {
        if ((*vit).id() == oid) {
            this->_dpoints.erase(vit);
            return true;
        }
    }

    return false;
}

bool object_system::add_dpoint(dpoint_entity dpoint) {
    bool exists = false;
    this->get_dpoint(dpoint.id(), exists);
    if (!exists) {
        this->_dpoints.push_back(dpoint);
        return true;
    }

    return false;
}

const vessel_entity* object_system::get_vessel(entity_id oid, bool &success) {
    vessel_entity *out = nullptr;

    success = false;
    for (vessel_entity &item : this->_vessels) {
        if (item.id() == oid) {
            success = true;
            out = &item;
            break;
        }
    }

    return out;
}

bool object_system::remove_vessel(entity_id oid) {
    auto vit = this->_vessels.begin();
    for (; vit != this->_vessels.end(); vit++) {
        if ((*vit).id() == oid) {
            this->_vessels.erase(vit);
            return true;
        }
    }

    return false;
}

bool object_system::add_vessel(vessel_entity dpoint) {
    bool exists = false;
    this->get_dpoint(dpoint.id(), exists);
    if (!exists) {
        this->_vessels.push_back(dpoint);
        return true;
    }

    return false;
}

void object_system::init(QDataStream &stream) {
    int dicnt;
    stream >> dicnt;
    this->_dpoints.resize(dicnt);
    for (int i = 0; i < dicnt; i++) {
        this->_dpoints[i].deserialize(stream);
    }

    int vicnt;
    stream >> vicnt;
    this->_vessels.resize(vicnt);
    for (int i = 0; i < vicnt; i++) {
        this->_vessels[i].deserialize(stream);
    }
}

void object_system::shutdown(QDataStream &stream) {
    stream << this->_dpoints.size();
    for (auto &item : this->_dpoints) {
        item.serialize(stream);
    }

    stream << this->_vessels.size();
    for (auto &item : this->_vessels) {
        item.serialize(stream);
    }
}
