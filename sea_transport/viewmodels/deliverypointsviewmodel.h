#ifndef DELIVERYPOINTSVIEWMODEL_H
#define DELIVERYPOINTSVIEWMODEL_H

#include "system/apparatus.h"

#include <QAbstractTableModel>


/**
 * @brief Delivery point ViewModel class
 * 
 */
class DeliveryPointsViewModel : public QAbstractTableModel {
private:
    Q_OBJECT

public:
    /**
     * @brief Construct a new Delivery point View Model object
     * 
     * @param parent [ignored]
     */
    DeliveryPointsViewModel(QObject *parent = nullptr);
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
     * @brief Update slot, may becalled then redraw needed
     * 
     */
    void update();
};

#endif // DELIVERYPOINTSVIEWMODEL_H
