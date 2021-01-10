#ifndef OBJECT_SYSTEM_H
#define OBJECT_SYSTEM_H

#include <QVector>

#include "../entities/dpoint_entity.h"
#include "../entities/vessel_entity.h"


/**
 * @brief Object's manipulation subsystem
 * 
 */
class object_system {
private:
    //! Subsystem's DP collection
    QVector<dpoint_entity> _dpoints;
    //! Subsystem's vessels collection
    QVector<vessel_entity> _vessels;

public:
    /**
     * @brief Construct a new object system object
     * 
     */
    object_system() = default;

    /**
     * @brief Get DP object
     * 
     * @param oid DP's ID
     * @param success operation success reference
     * @return dpoint_entity* 
     */
    dpoint_entity* get_dpoint(entity_id oid, bool &success);
    /**
     * @brief Remove DP from subsystem
     * 
     * @param oid DP's ID
     * @return true 
     * @return false 
     */
    bool remove_dpoint(entity_id oid);
    /**
     * @brief Add DP to subsystem
     * 
     * @param dpoint new DP object
     * @return true 
     * @return false 
     */
    bool add_dpoint(dpoint_entity dpoint);

    /**
     * @brief Get vessel object
     * 
     * @param oid vessel ID
     * @param success operation success reference
     * @return vessel_entity* 
     */
    vessel_entity* get_vessel(entity_id oid, bool &success);
    /**
     * @brief Remove vessel from subsystem
     * 
     * @param oid vessel's ID
     * @return true 
     * @return false 
     */
    bool remove_vessel(entity_id oid);
    /**
     * @brief Add vessel to subsystem
     * 
     * @param dpoint 
     * @return true 
     * @return false 
     */
    bool add_vessel(vessel_entity dpoint);


    /**
     * @brief Get subsystem immutable DP collection
     * 
     * @return const QVector<dpoint_entity> 
     */
    const QVector<dpoint_entity> dpoints() const;
    /**
     * @brief Get subsystem immutable vessel collection
     * 
     * @return const QVector<vessel_entity> 
     */
    const QVector<vessel_entity> vessels() const;

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

#endif // OBJECT_SYSTEM_H
