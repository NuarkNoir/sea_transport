#ifndef ISERIALIZABLE_H
#define ISERIALIZABLE_H

#include <QDataStream>


class ISerializable {
public:
    virtual void serialize(QDataStream &output) = 0;
    virtual void deserialize(QDataStream &input) = 0;

    friend QDataStream &operator<<(QDataStream &output, ISerializable &s) {
        s.serialize(output);
        return output;
    }

    friend QDataStream &operator>>(QDataStream  &input, ISerializable &s) {
        s.deserialize(input);
        return input;
    }
};

#endif // ISERIALIZABLE_H
