#ifndef USERENTITY_H
#define USERENTITY_H

#include <QString>

typedef long long pwd_type;

class UserEntity
{
    QString _login;
    pwd_type _password_hash;
    enum UserRoleEnum {
        ADMINISTRATOR = 0,
        DISPATCHER = 1,
        CAPTAIN = 2
    } _role;

public:
    UserEntity(QString login, QString password, UserEntity::UserRoleEnum role);
};

#endif // USERENTITY_H
