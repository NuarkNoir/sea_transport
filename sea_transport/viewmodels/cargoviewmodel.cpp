#include "cargoviewmodel.h"

CargoViewModel::CargoViewModel(QObject *parent) : QAbstractTableModel(parent) {

}

int CargoViewModel::rowCount(const QModelIndex &/*parent*/) const {
    return this->_data.length();
}

int CargoViewModel::columnCount(const QModelIndex &/*parent*/) const {
    return 3;
}

QVariant CargoViewModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("SID");
            case 1:
                return QString("Title");
            case 2:
                return QString("Volume");
        }
    }
    return QVariant();
}

QVariant CargoViewModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        auto item = this->_data[index.row()];

        int col = index.column();
        switch (col) {
            case 0:
                return QString::number(item.id());
            case 1:
                return item.title();
            case 2:
                return item.volume();
        }

        return "UNKNOWN FIELD";
    }

    return QVariant();
}

void CargoViewModel::set_data(const QVector<cargo_entity> &new_data) {
    this->beginResetModel();
    this->_data.clear();
    this->_data += new_data;
    this->endResetModel();
}
