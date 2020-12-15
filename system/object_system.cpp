#include "object_system.h"




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
