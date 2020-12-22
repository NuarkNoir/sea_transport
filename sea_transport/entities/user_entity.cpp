#include "user_entity.h"

user_entity::user_entity(const QString &login, const QString &password, UserRole role) : _login(login), _role(role) {
    this->_pwd_hash = QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha3_256);
}

entity_id user_entity::id() const {
    return this->_id;
}

const QString user_entity::login() const {
    return this->_login;
}

UserRole user_entity::role() const {
    return this->_role;
}

bool user_entity::verify_password(const QString &password) const {
    return (this->_pwd_hash == QCryptographicHash::hash(password.toLocal8Bit(), QCryptographicHash::Sha3_256));
}

void user_entity::set_password(const QString &new_password) {
    this->_pwd_hash = QCryptographicHash::hash(new_password.toLocal8Bit(), QCryptographicHash::Sha3_256);
}

void user_entity::set_role(UserRole new_role) {
    this->_role = new_role;
}

void user_entity::serialize(QDataStream &output) {
    output << this->_id << this->_login << this->_role << this->_pwd_hash;
}

void user_entity::deserialize(QDataStream &input) {
    input >> this->_id >> this->_login >> this->_role >> this->_pwd_hash;
}
