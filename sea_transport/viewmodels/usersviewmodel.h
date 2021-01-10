#ifndef USERSVIEWMODEL_H
#define USERSVIEWMODEL_H

#include "system/apparatus.h"

#include <QAbstractTableModel>


class UsersViewModel : public QAbstractTableModel {
private:
    Q_OBJECT

public:
    UsersViewModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    void update();
};

#endif // USERSVIEWMODEL_H
