#ifndef AUTH_SYSTEM_H
#define AUTH_SYSTEM_H

#include <QVector>

#include "../entities/user_entity.h"


/**
 * @brief User's manipulation subsystem
 * 
 */
class auth_system {
private:
    //! Subsystem's users collection
    QVector<user_entity> _users;
public:
    /**
     * @brief Construct a new auth system object
     * 
     */
    auth_system() = default;

    /**
     * @brief Get user
     * 
     * @param login user's login
     * @param success operation success reference
     * @return user_entity* 
     */
    user_entity* get_user(const QString &login, bool &success);
    /**
     * @brief Remove user from subsystem
     * 
     * @param login user's login
     * @return true 
     * @return false 
     */
    bool remove_user(const QString &login);
    /**
     * @brief Registeer new user in system
     * 
     * @param login new user's login
     * @param password new usere's password
     * @param role new user's role
     * @return true 
     * @return false 
     */
    bool register_user(const QString &login, const QString &password, UserRole role);

    /**
     * @brief Get subsystem immutable users collection
     * 
     * @return const QVector<user_entity>& 
     */
    const QVector<user_entity>& users() const;

    /**
     * @brief Reads subsytem's data from disk
     * 
     * @param stream read stream
     */
    void deserialize_data(QDataStream *stream);
    /**
     * @brief Writes subsytem's data to disk
     * 
     * @param stream write stream
     */
    void serialize_data(QDataStream *stream);
};

#endif // AUTH_SYSTEM_H
