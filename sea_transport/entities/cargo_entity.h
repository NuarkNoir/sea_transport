#ifndef CARGO_ENTITY_H
#define CARGO_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QCryptographicHash>


class cargo_entity : public IEntity {
private:
    entity_id _id;
    QString _title;
    unsigned int _volume;

public:
    cargo_entity() = default;
    cargo_entity(const QString &title, unsigned int volume);

    entity_id id() const;
    QString title() const;
    unsigned int volume() const;

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
};

#endif // CARGO_ENTITY_H
