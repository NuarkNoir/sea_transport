#include "vesselentity.h"

VesselEntity::VesselEntity(int v_id, QString hp, int mx_cap)
{
    this->_vessel_id = v_id;
    this->_home_port = hp;
    this->_max_capacity = mx_cap;
    this->_cargo_list.reserve(mx_cap);
}
