#include "usersviewmodel.h"

UsersViewModel::UsersViewModel(QObject *parent) : QAbstractTableModel(parent) {

}

int UsersViewModel::rowCount(const QModelIndex &/*parent*/) const {
    return apparatus::instance()->get_auth_subsystem()->users().length();
}

int UsersViewModel::columnCount(const QModelIndex &/*parent*/) const {
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
        auto item = apparatus::instance()->get_auth_subsystem()->users()[index.row()];

        int col = index.column();
        switch (col) {
            case 0:
                return QString::number(item.id());
            case 1:
                return item.login();
            case 2:
                QString _role = "unknown";

                switch(item.role()) {
                    case UserRole::ADMINISTRATOR:
                        _role = "Administrator";
                        break;
                    case UserRole::DISPATCHER:
                        _role = "Dispatcher";
                        break;
                    case UserRole::SKIPPER:
                        _role = "Skipper";
                        break;
                }

                return _role;
        }

        return "UNKNOWN FIELD";
    }

    return QVariant();
}

void UsersViewModel::update() {
    dataChanged(QModelIndex(),  QModelIndex());
}
