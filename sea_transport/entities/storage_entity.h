#ifndef STORAGE_ENTITY_H
#define STORAGE_ENTITY_H

#include "IEntity.h"
#include "cargo_entity.h"

#include <QVector>
#include <QRandomGenerator>


/**
 * @brief Storage entity class
 * 
 */
class storage_entity : public IEntity {
private:
    //! Global static ID for storage
    static entity_id __global_id;

    //! Storage object ID
    entity_id _id = 0;
    //! Storage's capacity
    unsigned int _capacity = 500000;
    //! Storages's cargo collection
    QVector<cargo_entity> _cargo;

public:
    /**
     * @brief Construct a new storage entity object
     * 
     */
    storage_entity();
    /**
     * @brief Construct a new storage entity object
     * 
     * @param capacity storage capacity
     */
    storage_entity(unsigned int capacity);

    /**
     * @brief Get storage's ID
     * 
     * @return entity_id 
     */
    entity_id id() const;
    /**
     * @brief Get storage's capacity
     * 
     * @return unsigned int 
     */
    unsigned int capacity() const;
    /**
     * @brief Set storage's capacity
     * 
     * @param new_capacity new capacity
     */
    void set_capacity(unsigned int new_capacity);
    /**
     * @brief Get immutable cargo collection
     * 
     * @return const QVector<cargo_entity> 
     */
    const QVector<cargo_entity> cargo();

    /**
     * @brief Add cargo object to storage collection
     * 
     * @param object new cargo
     * @param success operation success reference
     */
    void add_cargo(cargo_entity object, bool &success);
    /**
     * @brief Get the cargo object
     * 
     * @param oid cargo ID
     * @param found object found reference
     * @return cargo_entity 
     */
    cargo_entity get_cargo(entity_id oid, bool &found);
    /**
     * @brief Remove cargo from storage's collection
     * 
     * @param oid cargo ID
     * @param success operation success reference
     */
    void withdraw_cargo(entity_id oid, bool &success);

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

#endif // STORAGE_ENTITY_H
