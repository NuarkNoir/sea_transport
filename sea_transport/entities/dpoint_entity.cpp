#include "dpoint_entity.h"

dpoint_entity::dpoint_entity(const QString &title) : _title(title) {
    this->_id = 0;
    auto hash = QCryptographicHash::hash(title.toLocal8Bit(), QCryptographicHash::Md5);
    for (auto bit : hash) {
        this->_id += bit;
    }
}

entity_id dpoint_entity::id() {
    return this->_id;
}

QString dpoint_entity::title() {
    return this->_title;
}

const QVector<storage_entity> dpoint_entity::storages() {
    return this->_storages;
}

void dpoint_entity::serialize(QDataStream &output) {
    output << this->_id << this->_title << this->_storages.size();
    for (auto &item : this->_storages) {
        item.serialize(output);
    }
}

void dpoint_entity::deserialize(QDataStream &input) {
    int icnt;
    input >> this->_id >> this->_title >> icnt;
    this->_storages.resize(icnt);
    for (int i = 0; i < icnt; i++) {
        this->_storages[i].deserialize(input);
    }
}