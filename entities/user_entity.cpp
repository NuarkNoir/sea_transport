#include "user_entity.h"

user_entity::user_entity(const QString &login, const QString &password, UserRole role) {
    this->_pwd_hash = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha3_256);
}

unsigned long long user_entity::id() {
    return this->_id;
}

const QString user_entity::login() {
    return this->_login;
}

UserRole user_entity::role() {
    return this->_role;
}

bool user_entity::verify_password(const QString &password) {
    return (this->_pwd_hash == QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha3_256));
}
