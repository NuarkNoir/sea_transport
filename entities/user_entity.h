#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include <QString>
#include <QCryptographicHash>


enum class UserRole {
    ADMINISTRATOR, DISPATCHER, SKIPPER
};


class user_entity
{
private:
    unsigned long long _id;
    QString _login;
    UserRole _role;
    QByteArray _pwd_hash;

public:
    user_entity() = default;
    user_entity(const QString &login, const QString &password, UserRole role);

    unsigned long long id();
    const QString login();
    UserRole role();
    bool verify_password(const QString &password);
};

#endif // USER_ENTITY_H
