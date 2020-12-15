#include "cargo_entity.h"

cargo_entity::cargo_entity(const QString &title, int volume) : _title(title), _volume(volume) {
    this->_id = volume;
    auto hash = QCryptographicHash::hash(title.toLocal8Bit(), QCryptographicHash::Md5);
    for (auto bit : hash) {
        this->_id |= bit;
    }
}

unsigned long long cargo_entity::id() {
    return this->_id;
}

QString cargo_entity::title() {
    return this->_title;
}

unsigned int cargo_entity::volume() {
    return this->_volume;
}
