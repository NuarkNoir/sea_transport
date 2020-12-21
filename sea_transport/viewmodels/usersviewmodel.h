#ifndef USERSVIEWMODEL_H
#define USERSVIEWMODEL_H

#include "system/apparatus.h"

#include <QAbstractTableModel>

class UsersViewModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    UsersViewModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

public slots:
    void update();
};

#endif // USERSVIEWMODEL_H
