#ifndef DPOINT_ENTITY_H
#define DPOINT_ENTITY_H

#include "IEntity.h"
#include "storage_entity.h"

#include <QString>
#include <QVector>
#include <QCryptographicHash>


class dpoint_entity : public IEntity {
private:
    entity_id _id;
    QString _title;
    QVector<storage_entity> _storages;

public:
    dpoint_entity() = default;
    dpoint_entity(const QString &title);

    entity_id id() const;
    QString title() const;
    const QVector<storage_entity> storages();

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
};

#endif // DPOINT_ENTITY_H
