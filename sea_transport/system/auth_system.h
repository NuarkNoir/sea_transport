#ifndef AUTH_SYSTEM_H
#define AUTH_SYSTEM_H

#include<QVector>

#include <entities/user_entity.h>


class auth_system
{
private:
    QVector<user_entity> _users;
public:
    auth_system() = default;

    const user_entity* get_user(const QString &login, bool &success);
    bool remove_user(const QString &login);
    bool register_user(const QString &login, const QString &password, UserRole role);

    void init(QDataStream &stream);
    void shutdown(QDataStream &stream);
};

#endif // AUTH_SYSTEM_H
