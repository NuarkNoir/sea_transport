#ifndef USERSVIEWMODEL_H
#define USERSVIEWMODEL_H

#include "system/apparatus.h"

#include <QAbstractTableModel>


/**
 * @brief Users ViewModel class
 * 
 */
class UsersViewModel : public QAbstractTableModel {
private:
    Q_OBJECT

public:
    /**
     * @brief Construct a new Users View Model object
     * 
     * @param parent [ignored]
     */
    UsersViewModel(QObject *parent = nullptr);
    /**
     * @brief Returns row count
     * 
     * @param parent [ignored]
     * @return int 
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    /**
     * @brief Returns column count
     * 
     * @param parent [ignored]
     * @return int 
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    /**
     * @brief Returns data about header
     * 
     * @param section header section
     * @param orientation header orientation
     * @param role header cell role
     * @return QVariant 
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    /**
     * @brief Returns data about cells
     * 
     * @param index cell index
     * @param role draw role
     * @return QVariant 
     */
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

public slots:
    /**
     * @brief Update slot, may be called then redraw needed
     * 
     */
    void update();
};

#endif // USERSVIEWMODEL_H
