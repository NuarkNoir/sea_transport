#ifndef APPARATUS_H
#define APPARATUS_H

#include <QString>
#include <QFile>
#include <QDataStream>

#include <entities/vessel_entity.h>
#include <entities/storage_entity.h>


class apparatus
{
private:
    static apparatus *_instance;
    static const QString filename;

    QFile *_bin_file;
    QDataStream stream;

    void open_reading_stream();
    void open_writing_stream();
    void close_stream();

    void writeGIDS();
    void loadGIDS();

    void serialize_data();
    void deserialize_data();

public:
    apparatus();
    ~apparatus();

    bool isFirstRun();

    static apparatus& instance();
    static void init();
    static void shutdown();
};

#endif // APPARATUS_H
