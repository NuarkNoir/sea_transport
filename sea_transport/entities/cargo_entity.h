#ifndef CARGO_ENTITY_H
#define CARGO_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QRandomGenerator>
#include <QCryptographicHash>


class cargo_entity : public IEntity {
private:
    entity_id _id = 0;
    QString _title;
    unsigned int _volume = 50000;

public:
    cargo_entity();
    cargo_entity(const QString &title, unsigned int volume);

    entity_id id() const;
    QString title() const;
    unsigned int volume() const;

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
};

#endif // CARGO_ENTITY_H
