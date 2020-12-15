#ifndef STORAGE_ENTITY_H
#define STORAGE_ENTITY_H

#include "IEntity.h"
#include "cargo_entity.h"

#include <QVector>
#include <QCryptographicHash>


class storage_entity : public IEntity {
private:
    static entity_id __global_id;

    entity_id _id;
    unsigned int _capacity;
    QVector<cargo_entity> _cargo;

public:
    storage_entity() = default;
    storage_entity(unsigned int capacity);

    entity_id id();
    unsigned int capacity();
    const QVector<cargo_entity> cargo();

    void add_cargo(cargo_entity object, bool &success);
    cargo_entity get_cargo(entity_id oid, bool &found);
    void withdraw_cargo(entity_id oid, bool &success);

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
    void preloadGlobalId(entity_id gid);
};

#endif // STORAGE_ENTITY_H
