#ifndef VESSELSVIEWMODEL_H
#define VESSELSVIEWMODEL_H

#include "system/apparatus.h"

#include <QAbstractTableModel>

class VesselsViewModel : public QAbstractTableModel {
    Q_OBJECT

public:
    VesselsViewModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    void update();
};

#endif // VESSELSVIEWMODEL_H
