#ifndef CARGOVIEWMODEL_H
#define CARGOVIEWMODEL_H

#include <QVector>
#include <QAbstractTableModel>

#include "entities/cargo_entity.h"

class CargoViewModel : public QAbstractTableModel {
    Q_OBJECT

    QVector<cargo_entity> _data;

public:
    CargoViewModel(QObject *parent);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

    void set_data(const QVector<cargo_entity> &new_data);
};

#endif // CARGOVIEWMODEL_H
