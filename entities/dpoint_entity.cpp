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

const QVector<entity_id> dpoint_entity::storages_ids() {
    return this->_storages_ids;
}

void dpoint_entity::serialize(QDataStream &output) {
    output << this->_id << this->_title << this->_storages_ids;
}

void dpoint_entity::deserialize(QDataStream &input) {
    input >> this->_id >> this->_title >> this->_storages_ids;
}
