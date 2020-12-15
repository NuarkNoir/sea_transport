#ifndef CARGO_ENTITY_H
#define CARGO_ENTITY_H

#include <QString>
#include <QCryptographicHash>


class cargo_entity
{
private:
    unsigned long long _id;
    QString _title;
    unsigned int _volume;

public:
    cargo_entity() = default;
    cargo_entity(const QString &title, int volume);

    unsigned long long id();
    QString title();
    unsigned int volume();
};

#endif // CARGO_ENTITY_H
