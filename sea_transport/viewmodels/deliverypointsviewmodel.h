#ifndef DELIVERYPOINTSVIEWMODEL_H
#define DELIVERYPOINTSVIEWMODEL_H

#include "system/apparatus.h"

#include <QAbstractTableModel>


class DeliveryPointsViewModel : public QAbstractTableModel {
private:
    Q_OBJECT

public:
    DeliveryPointsViewModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    void update();
};

#endif // DELIVERYPOINTSVIEWMODEL_H
