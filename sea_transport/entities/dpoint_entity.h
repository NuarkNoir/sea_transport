#ifndef DPOINT_ENTITY_H
#define DPOINT_ENTITY_H

#include "IEntity.h"
#include "storage_entity.h"

#include <QString>
#include <QVector>
#include <QRandomGenerator>
#include <QCryptographicHash>


class dpoint_entity : public IEntity {
private:
    //! Global static ID for delivery point
    static entity_id __global_id;

    //! Delivery point ID
    entity_id _id = 0;
    //! Delivery point dispatcher
    entity_id _dispatcher_id;
    //! Delivery point title
    QString _title;
    //! Delivery point storage collection
    QVector<storage_entity> _storages;

public:
    /**
     * @brief Construct a new dpoint entity object
     * 
     */
    dpoint_entity();
    /**
     * @brief Construct a new dpoint entity object
     * 
     * @param dispatcher_id dispatcher's ID
     * @param title DP's title
     */
    dpoint_entity(entity_id dispatcher_id, const QString &title);

    /**
     * @brief Get delivery point ID
     * 
     * @return entity_id 
     */
    entity_id id() const;
    /**
     * @brief Get delivery point dispatcher
     * 
     * @return entity_id 
     */
    entity_id dispatcher() const;
    /**
     * @brief Get delivery point title
     * 
     * @return QString 
     */
    QString title() const;
    /**
     * @brief Set delivery point title
     * 
     * @param new_title new title
     */
    void set_title(const QString &new_title);
    /**
     * @brief Get immutable delivery point's storages collection
     * 
     * @return const QVector<storage_entity> 
     */
    const QVector<storage_entity> storages();
    /**
     * @brief Get delivery point's storage
     * 
     * @param sid storage ID
     * @param success object found reference
     * @return storage_entity* 
     */
    storage_entity* get_storage(entity_id sid, bool &success);
    /**
     * @brief Set storages of delivery point
     * 
     * @param storages new storages collection
     */
    void set_storages(QVector<storage_entity> storages);
    /**
     * @brief Remove storage from delivery point's collection
     * 
     * @param sid storage ID
     */
    void remove_storage(entity_id sid);
    /**
     * @brief Add storage entity to delivery point's collection
     * 
     * @param ent new storage
     */
    void add_storage(storage_entity ent);

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

#endif // DPOINT_ENTITY_H
