#include "vesselsviewmodel.h"

VesselsViewModel::VesselsViewModel(QObject *parent) : QAbstractTableModel(parent) {

}

int VesselsViewModel::rowCount(const QModelIndex &/*parent*/) const {
    return apparatus::instance()->get_object_subsystem()->vessels().length();
}

int VesselsViewModel::columnCount(const QModelIndex &/*parent*/) const {
    return 5;
}

QVariant VesselsViewModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("VID");
            case 1:
                return QString("Harbor");
            case 2:
                return QString("Capacity");
            case 3:
                return QString("Cargo count");
            case 4:
                return QString("Cargo volume");
        }
    }
    return QVariant();
}

QVariant VesselsViewModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        auto item = apparatus::instance()->get_object_subsystem()->vessels()[index.row()];
        bool s = false;
        auto harbor = apparatus::instance()->get_object_subsystem()->get_dpoint(item.harbor(), s);

        int col = index.column();
        switch (col) {
            case 0:
                return QString::number(item.id());
            case 1:
                return (s? harbor->title() : "##ERROR##");
            case 2:
                return item.capacity();
            case 3:
                return item.cargo().length();
            case 4:
                int cvol = 0;
                foreach (auto cargo, item.cargo()) {
                    cvol += cargo.volume();
                }
                return cvol;
        }

        return "UNKNOWN FIELD";
    }

    return QVariant();
}

void VesselsViewModel::update() {
    dataChanged(QModelIndex(),  QModelIndex());
}
