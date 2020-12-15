#ifndef CARGO_ENTITY_H
#define CARGO_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QCryptographicHash>


class cargo_entity : public IEntity {
private:
    unsigned long long _id;
    QString _title;
    unsigned int _volume;

public:
    cargo_entity() = default;
    cargo_entity(const QString &title, unsigned int volume);

    unsigned long long id();
    QString title();
    unsigned int volume();

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
};

#endif // CARGO_ENTITY_H
