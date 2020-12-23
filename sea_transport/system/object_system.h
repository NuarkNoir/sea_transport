#ifndef OBJECT_SYSTEM_H
#define OBJECT_SYSTEM_H

#include <QVector>

#include "../entities/dpoint_entity.h"
#include "../entities/vessel_entity.h"


class object_system
{
private:
    QVector<dpoint_entity> _dpoints;
    QVector<vessel_entity> _vessels;

public:
    object_system() = default;

    dpoint_entity* get_dpoint(entity_id oid, bool &success);
    bool remove_dpoint(entity_id oid);
    bool add_dpoint(dpoint_entity dpoint);

    vessel_entity* get_vessel(entity_id oid, bool &success);
    bool remove_vessel(entity_id oid);
    bool add_vessel(vessel_entity dpoint);


    const QVector<dpoint_entity> dpoints() const;
    const QVector<vessel_entity> vessels() const;

    void deserialize_data(QDataStream *stream);
    void serialize_data(QDataStream *stream);
};

#endif // OBJECT_SYSTEM_H
