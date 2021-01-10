#ifndef CARGO_ENTITY_H
#define CARGO_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QRandomGenerator>
#include <QCryptographicHash>


/**
 * @brief Cargo entity class
 * 
 */
class cargo_entity : public IEntity {
private:
    //! Global static ID for cargo
    static entity_id __global_id;

    //! Cargo's ID
    entity_id _id = 0;
    //! Cargo title
    QString _title;
    //! Cargo volume
    unsigned int _volume = 50000;

public:
    /**
    * @brief Construct a new cargo entity object
    * 
    */
    cargo_entity();
    /**
     * @brief Construct a new cargo entity object
     * 
     * @param title cargo title
     * @param volume cargo volume
     */
    cargo_entity(const QString &title, unsigned int volume);

    /**
     * @brief Get cargo's ID
     * 
     * @return entity_id 
     */
    entity_id id() const;
    /**
     * @brief Get cargo's title
     * 
     * @return QString 
     */
    QString title() const;
    /**
     * @brief Get cargo's volume
     * 
     * @return unsigned int 
     */
    unsigned int volume() const;

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

#endif // CARGO_ENTITY_H
