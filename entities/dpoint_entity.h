#ifndef DPOINT_ENTITY_H
#define DPOINT_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QVector>
#include <QCryptographicHash>


class dpoint_entity : public IEntity {
private:
    entity_id _id;
    QString _title;
    QVector<entity_id> _storages_ids;

public:
    dpoint_entity() = default;
    dpoint_entity(const QString &title);

    entity_id id();
    QString title();
    const QVector<entity_id> storages_ids();

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
};

#endif // DPOINT_ENTITY_H
