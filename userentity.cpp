#include "userentity.h"

UserEntity::UserEntity(QString login, QString password, UserEntity::UserRoleEnum role)
{
    this->_login = login;

    this->_password_hash = 0;
    for (auto pchar : password) {
        this->_password_hash += pchar.unicode();
    }
    this->_password_hash %= (1 << 16);

    this->_role = role;
}
