#include "dpoint_entity.h"

dpoint_entity::dpoint_entity(const QString &title) : _title(title) {
    this->_id = 0;
    auto hash = QCryptographicHash::hash(title.toLocal8Bit(), QCryptographicHash::Md5);
    for (auto bit : hash) {
        this->_id += bit;
    }
}

unsigned long long dpoint_entity::id() {
    return this->_id;
}

QString dpoint_entity::title() {
    return this->_title;
}

const QVector<unsigned long long> dpoint_entity::storages_ids() {
    return this->_storages_ids;
}
