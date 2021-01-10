#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <QDataStream>

/**
 * @brief Interface for any serializable object
 * 
 */
class ISerializable {
public:
    /**
     * @brief Write-obect-to-disk function
     * 
     * @param output output stream
     */
    virtual void serialize(QDataStream &output) = 0;
    /**
     * @brief Read-object-from-disk function
     * 
     * @param input input stream
     */
    virtual void deserialize(QDataStream &input) = 0;
};

#endif // ISERIALIZABLE_H
