#ifndef CARGOENTITY_H
#define CARGOENTITY_H

#include "deliverypointentity.h"

#include <QString>


class DeliveryPointEntity;
class StorageEntity;
class CargoEntity
{
    QString _cargo_id;
    DeliveryPointEntity *_destination;

public:
    CargoEntity();
    CargoEntity(QString _cargo_id, DeliveryPointEntity *_destination);
};

#endif // CARGOENTITY_H
