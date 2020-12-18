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

    const dpoint_entity* get_dpoint(entity_id oid, bool &success);
    bool remove_dpoint(entity_id oid);
    bool add_dpoint(dpoint_entity dpoint);

    const vessel_entity* get_vessel(entity_id oid, bool &success);
    bool remove_vessel(entity_id oid);
    bool add_vessel(vessel_entity dpoint);


    void init(QDataStream &stream);
    void shutdown(QDataStream &stream);
};

#endif // OBJECT_SYSTEM_H
