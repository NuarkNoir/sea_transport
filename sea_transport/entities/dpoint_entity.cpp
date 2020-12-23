#include "dpoint_entity.h"


dpoint_entity::dpoint_entity() {
    this->_id += QRandomGenerator().generate64();
}

dpoint_entity::dpoint_entity(entity_id dispatcher_id, const QString &title) : _dispatcher_id(dispatcher_id), _title(title) {
    this->_id = dispatcher_id;
    auto hash = QCryptographicHash::hash(title.toLocal8Bit(), QCryptographicHash::Md5);
    for (auto bit : hash) {
        this->_id += bit;
    }
    this->_id += QRandomGenerator().generate64();
}

entity_id dpoint_entity::id() const {
    return this->_id;
}

entity_id dpoint_entity::dispatcher() const {
    return this->_dispatcher_id;
}

QString dpoint_entity::title() const {
    return this->_title;
}

void dpoint_entity::set_title(const QString &new_title) {
    this->_title = new_title;
}

const QVector<storage_entity> dpoint_entity::storages() {
    return this->_storages;
}

storage_entity* dpoint_entity::get_storage(entity_id sid, bool &success) {
    success = false;
    for (int i = 0; i < this->_storages.length(); i++) {
        if (this->_storages[i].id() != sid) {
            continue;
        }
        success = true;
        return &this->_storages[i];
    }

    return nullptr;
}

void dpoint_entity::set_storages(QVector<storage_entity> storages) {
    this->_storages = storages;
}

void dpoint_entity::remove_storage(entity_id sid) {
    QVector<storage_entity> st(this->_storages);

    for (int i = 0; i < st.length(); i++) {
        if (st[i].id() == sid) {
            st.removeAt(i);
            break;
        }
    }

    this->set_storages(st);
}

void dpoint_entity::add_storage(storage_entity ent) {
    this->_storages.push_back(ent);
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
