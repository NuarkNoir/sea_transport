#ifndef VESSEL_ENTITY_H
#define VESSEL_ENTITY_H

#include "cargo_entity.h"
#include "dpoint_entity.h"



class vessel_entity
{
private:
    static unsigned long long __global_id;

    unsigned long long _id;
    dpoint_entity _harbor;
    unsigned int _capacity;
    QVector<cargo_entity> _cargo;

public:
    vessel_entity() = default;
    vessel_entity(const dpoint_entity &harbor, unsigned int capacity);

    unsigned long long id();
    const dpoint_entity harbor();
    unsigned int capacity();
    const QVector<cargo_entity> cargo();
};

#endif // VESSEL_ENTITY_H
