#include "apparatus.h"
#include "auth_system.h"
#include <iostream>


const user_entity* auth_system::get_user(const QString &login, bool &success) {
    user_entity *out = nullptr;

    success = false;
    for (user_entity &item : this->_users) {
        if (item.login() == login) {
            success = true;
            out = &item;
            break;
        }
    }

    return out;
}

bool auth_system::remove_user(const QString &login) {
    auto vit = this->_users.begin();
    for (; vit != this->_users.end(); vit++) {
        if ((*vit).login() == login) {
            this->_users.erase(vit);
            return true;
        }
    }

    return false;
}

bool auth_system::register_user(const QString &login, const QString &password, UserRole role) {
    bool exists = false;
    this->get_user(login, exists);
    if (!exists) {
        std::cout << apparatus::instance()->get_auth_subsystem()->users().length() << std::endl;
        this->_users.push_back(user_entity(login, password, role));
        std::cout << apparatus::instance()->get_auth_subsystem()->users().length() << std::endl;
        apparatus::instance()->save();
        std::cout << apparatus::instance()->get_auth_subsystem()->users().length() << std::endl;
        return true;
    }

    return false;
}

const QVector<user_entity>& auth_system::users() const {
    return this->_users;
}

void auth_system::deserialize_data(QDataStream *stream) {
    int icnt;
    *stream >> icnt;
    if (icnt > 0) {
        this->_users.resize(icnt);
        for (int i = 0; i < icnt; i++) {
            this->_users[i].deserialize(*stream);
        }
    }
}

void auth_system::serialize_data(QDataStream *stream) {
    *stream << this->_users.size();
    for (auto &item : this->_users) {
        item.serialize(*stream);
    }
}
