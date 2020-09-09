#ifndef DELIVERYPOINTENTITY_H
#define DELIVERYPOINTENTITY_H

#include "storageentity.h"

#include <QString>
#include <vector>


class DeliveryPointEntity
{
    QString _title;
    std::vector<StorageEntity> _storage;

public:
    DeliveryPointEntity(QString title);
};

#endif // DELIVERYPOINTENTITY_H
