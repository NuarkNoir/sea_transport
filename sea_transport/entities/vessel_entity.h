#ifndef VESSEL_ENTITY_H
#define VESSEL_ENTITY_H

#include "IEntity.h"
#include "cargo_entity.h"
#include "dpoint_entity.h"


class vessel_entity : public IEntity {
private:
    static entity_id __global_id;

    entity_id _id;
    entity_id _skipper_id;
    entity_id _harbor_id;
    unsigned int _capacity;
    QVector<cargo_entity> _cargo;

public:
    vessel_entity() = default;
    vessel_entity(entity_id skipper_id, entity_id harbor_id, unsigned int capacity);

    entity_id id() const;
    entity_id harbor() const;
    unsigned int capacity() const;
    const QVector<cargo_entity> cargo();

    void add_cargo(cargo_entity object, bool &success);
    void withdraw_cargo(entity_id oid, bool &success);

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
    static void preloadGlobalId(entity_id gid);
    static entity_id GID();
};

#endif // VESSEL_ENTITY_H
