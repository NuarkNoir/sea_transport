#ifndef AUTH_SYSTEM_H
#define AUTH_SYSTEM_H

#include <QVector>

#include "../entities/user_entity.h"


class auth_system {
private:
    QVector<user_entity> _users;
public:
    auth_system() = default;

    user_entity* get_user(const QString &login, bool &success);
    bool remove_user(const QString &login);
    bool register_user(const QString &login, const QString &password, UserRole role);

    const QVector<user_entity>& users() const;

    void deserialize_data(QDataStream *stream);
    void serialize_data(QDataStream *stream);
};

#endif // AUTH_SYSTEM_H
