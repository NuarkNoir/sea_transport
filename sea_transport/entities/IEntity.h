#ifndef IENTITY_H
#define IENTITY_H

#include "ISerializable.h"


typedef unsigned long long entity_id;

class IEntity : public ISerializable {
public:
   virtual entity_id id() const = 0;
};

#endif // IENTITY_H
