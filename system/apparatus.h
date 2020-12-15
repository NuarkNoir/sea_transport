#ifndef APPARATUS_H
#define APPARATUS_H

#include <QFile>
#include <QDataStream>


class apparatus
{
private:
    static apparatus *_instance;

    QFile _bin_file;
    QDataStream stream;

    void open_reading_stream();
    void close_reading_stream();

    void open_writing_stream();
    void close_writing_stream();

    void writeGIDS();
    void loadGIDS();

    void serialize_data();
    void deserialize_data();

public:
    apparatus();

    static apparatus& instance();
    static void init();
    static void shutdown();
};

#endif // APPARATUS_H
