#ifndef IENTITY_H
#define IENTITY_H

#include "ISerializable.h"


//! Alias type for any entity ID
typedef unsigned long long entity_id;

/**
 * @brief Base interface for all entities
 * 
 */
class IEntity : public ISerializable {
public:
   /**
    * @brief Getter function for entity identificator
    * 
    * @return entity_id entity identficator
    */
   virtual entity_id id() const = 0;
};

#endif // IENTITY_H
