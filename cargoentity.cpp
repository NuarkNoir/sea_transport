#include "cargoentity.h"

CargoEntity::CargoEntity(QString c_id, DeliveryPointEntity dest)
{
    this->_cargo_id = c_id;
    this->_destination = dest;
}
