#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <QDataStream>


class ISerializable {
public:
    virtual void serialize(QDataStream &output) = 0;
    virtual void deserialize(QDataStream &input) = 0;
};

#endif // ISERIALIZABLE_H
