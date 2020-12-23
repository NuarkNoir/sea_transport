#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QRandomGenerator>
#include <QCryptographicHash>


enum class UserRole {
    ADMINISTRATOR, DISPATCHER, SKIPPER
};


class user_entity : public IEntity {
private:
    static entity_id __global_id;

    entity_id _id = 0;
    QString _login;
    UserRole _role;
    QByteArray _pwd_hash;

public:
    user_entity();
    user_entity(const QString &login, const QString &password, UserRole role);

    entity_id id() const;
    const QString login() const;
    UserRole role() const;
    bool verify_password(const QString &password) const;
    void set_password(const QString &new_password);
    void set_role(UserRole new_role);

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
    static void preloadGlobalId(entity_id gid);
    static entity_id GID();
};

#endif // USER_ENTITY_H
