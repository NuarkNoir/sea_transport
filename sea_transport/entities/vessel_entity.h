#ifndef VESSEL_ENTITY_H
#define VESSEL_ENTITY_H

#include "IEntity.h"
#include "cargo_entity.h"
#include "dpoint_entity.h"

#include <QRandomGenerator>


/**
 * @brief Vessel entity class
 * 
 */
class vessel_entity : public IEntity {
private:
    //! Global static ID for vessels
    static entity_id __global_id;

    //! Vessel ID
    entity_id _id = 0;
    //! Skipper login
    QString _skipper;
    //! Harbor ID
    entity_id _harbor_id;
    //! Vessel capacity
    unsigned int _capacity = 50000;
    //! Vessel's cargo collection
    QVector<cargo_entity> _cargo;

public:
    /**
     * @brief Construct a new vessel entity object
     * 
     */
    vessel_entity();
    /**
     * @brief Construct a new vessel entity object
     * 
     * @param skipper skipper login
     * @param harbor_id harbor ID
     * @param capacity vessel capacity
     */
    vessel_entity(QString skipper, entity_id harbor_id, unsigned int capacity);

    entity_id id() const;
    /**
     * @brief Get skipper login
     * 
     * @return QString 
     */
    QString skipper() const;
    /**
     * @brief Set skipper login
     * 
     * @param new_skipper new skipper login
     */
    void set_skipper(const QString &new_skipper);
    /**
     * @brief Get harbor ID
     * 
     * @return entity_id 
     */
    entity_id harbor() const;
    /**
     * @brief Set harbor object
     * 
     * @param new_harbor new harbor ID
     */
    void set_harbor(entity_id new_harbor);
    /**
     * @brief Get capacity of vessel
     * 
     * @return unsigned int 
     */
    unsigned int capacity() const;
    /**
     * @brief Set capacity object
     * 
     * @param new_capacity new vessel capacity
     */
    void set_capacity(unsigned int new_capacity);
    /**
     * @brief Get vessel's immutable cargo collection
     * 
     * @return const QVector<cargo_entity> 
     */
    const QVector<cargo_entity> cargo();

    /**
     * @brief Add cargo to vessel's collection
     * 
     * @param object new cargo
     * @param success operation success reference
     */
    void add_cargo(cargo_entity object, bool &success);
    /**
     * @brief Get cargo object
     * 
     * @param oid cargo ID
     * @param found object found reference
     * @return cargo_entity 
     */
    cargo_entity get_cargo(entity_id oid, bool &found);
    /**
     * @brief Remove cargo from vessel's collection
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

#endif // VESSEL_ENTITY_H
