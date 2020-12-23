#ifndef VESSEL_ENTITY_H
#define VESSEL_ENTITY_H

#include "IEntity.h"
#include "cargo_entity.h"
#include "dpoint_entity.h"

#include <QRandomGenerator>


class vessel_entity : public IEntity {
private:
    static entity_id __global_id;

    entity_id _id = 0;
    QString _skipper;
    entity_id _harbor_id;
    unsigned int _capacity = 50000;
    QVector<cargo_entity> _cargo;

public:
    vessel_entity();
    vessel_entity(QString skipper, entity_id harbor_id, unsigned int capacity);

    entity_id id() const;
    QString skipper() const;
    void set_skipper(const QString &new_skipper);
    entity_id harbor() const;
    void set_harbor(entity_id new_harbor);
    unsigned int capacity() const;
    void set_capacity(unsigned int new_capacity);
    const QVector<cargo_entity> cargo();

    void add_cargo(cargo_entity object, bool &success);
    cargo_entity get_cargo(entity_id oid, bool &found);
    void withdraw_cargo(entity_id oid, bool &success);

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
    static void preloadGlobalId(entity_id gid);
    static entity_id GID();
};

#endif // VESSEL_ENTITY_H
