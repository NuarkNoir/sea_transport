#ifndef DELIVERYPOINTENTITY_H
#define DELIVERYPOINTENTITY_H

#include "storageentity.h"

#include <QString>
#include <vector>


class CargoEntity;
class StorageEntity;
class DeliveryPointEntity
{
    QString _title;
    std::vector<StorageEntity> _storage;

public:
    DeliveryPointEntity();
    DeliveryPointEntity(QString title);
};

#endif // DELIVERYPOINTENTITY_H
