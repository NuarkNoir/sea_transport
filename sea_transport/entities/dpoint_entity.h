#ifndef DPOINT_ENTITY_H
#define DPOINT_ENTITY_H

#include "IEntity.h"
#include "storage_entity.h"

#include <QString>
#include <QVector>
#include <QRandomGenerator>
#include <QCryptographicHash>


class dpoint_entity : public IEntity {
private:
    entity_id _id;
    entity_id _dispatcher_id;
    QString _title;
    QVector<storage_entity> _storages;

public:
    dpoint_entity() = default;
    dpoint_entity(entity_id dispatcher_id, const QString &title);

    entity_id id() const;
    entity_id dispatcher() const;
    QString title() const;
    void set_title(const QString &new_title);
    const QVector<storage_entity> storages();
    void set_storages(QVector<storage_entity> storages);
    void remove_storage(entity_id sid);
    void add_storage(storage_entity ent);

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
};

#endif // DPOINT_ENTITY_H
