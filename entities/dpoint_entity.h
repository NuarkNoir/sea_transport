#ifndef DPOINT_ENTITY_H
#define DPOINT_ENTITY_H

#include "IEntity.h"

#include <QString>
#include <QVector>
#include <QCryptographicHash>


class dpoint_entity : public IEntity {
private:
    unsigned long long _id;
    QString _title;
    QVector<unsigned long long> _storages_ids;

public:
    dpoint_entity() = default;
    dpoint_entity(const QString &title);

    unsigned long long id();
    QString title();
    const QVector<unsigned long long> storages_ids();

    void serialize(QDataStream &output);
    void deserialize(QDataStream &input);
};

#endif // DPOINT_ENTITY_H
