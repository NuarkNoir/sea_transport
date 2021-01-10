#include "deliverypointsviewmodel.h"


DeliveryPointsViewModel::DeliveryPointsViewModel(QObject *parent) : QAbstractTableModel(parent) {

}

int DeliveryPointsViewModel::rowCount(const QModelIndex &/*parent*/) const {
    return apparatus::instance()->get_object_subsystem()->dpoints().length();
}

int DeliveryPointsViewModel::columnCount(const QModelIndex &/*parent*/) const {
    return 4;
}

QVariant DeliveryPointsViewModel::headerData(int section, Qt::Orientation orientation,
                                             int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("DPID");
            case 1:
                return QString("Title");
            case 2:
                return QString("Storages count");
            case 3:
                return QString("Storages total volume");
        }
    }
    return QVariant();
}

QVariant DeliveryPointsViewModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        auto item = apparatus::instance()->get_object_subsystem()->dpoints()[index.row()];

        int col = index.column();
        switch (col) {
            case 0:
                return QString::number(item.id());
            case 1:
                return item.title();
            case 2:
                return item.storages().length();
            case 3:
                int tvol = 0;
                foreach (auto storage, item.storages()) {
                    tvol += storage.capacity();
                }
                return tvol;
        }

        return "UNKNOWN FIELD";
    }

    return QVariant();
}

void DeliveryPointsViewModel::update() {
    this->beginResetModel();
    this->endResetModel();
}
