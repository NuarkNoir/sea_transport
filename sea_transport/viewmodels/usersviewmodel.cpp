#include "usersviewmodel.h"

UsersViewModel::UsersViewModel(QObject *parent) : QAbstractTableModel(parent) {

}

int UsersViewModel::rowCount(const QModelIndex & /*parent*/) const {
    return apparatus::instance()->get_object_subsystem().vessels().size();
}

int UsersViewModel::columnCount(const QModelIndex & /*parent*/) const {
    return 3;
}

QVariant UsersViewModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QString("UID");
            case 1:
                return QString("Login");
            case 2:
                return QString("Role");
        }
    }
    return QVariant();
}

QVariant UsersViewModel::data(const QModelIndex &index, int role) const {
    if (role == Qt::DisplayRole) {
        auto item = apparatus::instance()->get_auth_subsystem().users()[index.row()];
        int col = index.column();

        switch (col) {
            case 0:
                return QString::number(item.id());
            case 1:
                return item.login();
            case 2:
                QString role = "unknown";

                switch(item.role()) {
                    case UserRole::ADMINISTRATOR:
                        role = "Administrator";
                        break;
                    case UserRole::DISPATCHER:
                        role = "Dispatcher";
                        break;
                    case UserRole::SKIPPER:
                        role = "Skipper";
                        break;
                }

                return role;
        }

        return "UNKNOWN FIELD";
    }

    return QVariant();
}

void UsersViewModel::update() {
    this->resetInternalData();
}
