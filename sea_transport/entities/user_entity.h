#ifndef USER_ENTITY_H
#define USER_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QRandomGenerator>
#include <QCryptographicHash>


/**
 * @brief Defines user account type
 * 
 */
enum class UserRole {
    ADMINISTRATOR,  //< User is administrator
    DISPATCHER,     //< User is dispatcher
    SKIPPER         //< User is skipper
};

/**
 * @brief Class for user entity
 * 
 */
class user_entity : public IEntity {
private:
    //! Global static ID for users
    static entity_id __global_id;

    //! Object ID
    entity_id _id = 0;
    //! User's login
    QString _login;
    //! User's role
    UserRole _role;
    //! User's password hash
    QByteArray _pwd_hash;

public:
    /**
     * @brief Construct a new user entity object
     * 
     */
    user_entity();
    /**
     * @brief Construct a new user entity object
     * 
     * @param login new user's login 
     * @param password new user's password
     * @param role new user's account role
     */
    user_entity(const QString &login, const QString &password, UserRole role);

    /**
     * @brief Get user's ID
     * 
     * @return entity_id 
     */
    entity_id id() const;
    /**
     * @brief Get user's login
     * 
     * @return const QString 
     */
    const QString login() const;
    /**
     * @brief Get user's account role
     * 
     * @return UserRole 
     */
    UserRole role() const;
    /**
     * @brief Verify password
     * 
     * @param password password to be verified
     * @return true passwords match
     * @return false passwords do not mattch
     */
    bool verify_password(const QString &password) const;
    /**
     * @brief Set user's password
     * 
     * @param new_password new password
     */
    void set_password(const QString &new_password);
    /**
     * @brief Set user's role
     * 
     * @param new_role 
     */
    void set_role(UserRole new_role);

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
    /**
     * @brief Sets GID of class
     * 
     * @param gid new class GID
     */
    static void preloadGlobalId(entity_id gid);
    /**
     * @brief Returns GID of class
     * 
     * @return entity_id 
     */
    static entity_id GID();
};

#endif // USER_ENTITY_H
