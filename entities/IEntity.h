#ifndef IENTITY_H
#define IENTITY_H

#include "ISerializable.h"


class IEntity : public ISerializable {
public:
   virtual unsigned long long id() = 0;
};

#endif // IENTITY_H
