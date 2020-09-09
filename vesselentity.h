#ifndef VESSELENTITY_H
#define VESSELENTITY_H

#include "cargoentity.h"

#include <QString>
#include <vector>


class VesselEntity
{
    int _vessel_id;
    QString _home_port;
    int _max_capacity;
    std::vector<CargoEntity> _cargo_list;

public:
    VesselEntity(int v_id, QString hp, int mx_cap);
};

#endif // VESSELENTITY_H
