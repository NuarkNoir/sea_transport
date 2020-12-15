#ifndef DPOINT_ENTITY_H
#define DPOINT_ENTITY_H

#include <QString>
#include <QVector>
#include <QCryptographicHash>


class dpoint_entity
{
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
};

#endif // DPOINT_ENTITY_H
