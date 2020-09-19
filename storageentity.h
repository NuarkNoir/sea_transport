#ifndef STORAGEENTITY_H
#define STORAGEENTITY_H

#include "cargoentity.h"

#include <vector>

class DeliveryPointEntity;
class CargoEntity;
class StorageEntity
{
    int _storage_id;
    int _max_capacity;
    std::vector<CargoEntity> _cargo;

public:
    StorageEntity();
    StorageEntity(int st_id, int mx_cap);
};

#endif // STORAGEENTITY_H
