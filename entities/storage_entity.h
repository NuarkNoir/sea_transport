#ifndef STORAGE_ENTITY_H
#define STORAGE_ENTITY_H

#include "cargo_entity.h"

#include <QVector>
#include <QCryptographicHash>


class storage_entity
{
private:
    static unsigned long long __global_id;

    unsigned long long _id;
    unsigned int _capacity;
    QVector<cargo_entity> _cargo;

public:
    storage_entity() = default;
    storage_entity(unsigned int capacity);

    unsigned long long id();
    unsigned int capacity();
    const QVector<cargo_entity> cargo();
};

#endif // STORAGE_ENTITY_H
