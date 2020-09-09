#include "storageentity.h"

StorageEntity::StorageEntity(int st_id, int mx_cap)
{
    this->_storage_id = st_id;
    this->_max_capacity = mx_cap;
    this->_cargo.reserve(mx_cap);
}
