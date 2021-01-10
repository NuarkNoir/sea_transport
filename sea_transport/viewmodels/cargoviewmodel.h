#ifndef CARGOVIEWMODEL_H
#define CARGOVIEWMODEL_H

#include <QVector>
#include <QAbstractTableModel>

#include "entities/cargo_entity.h"


/**
 * @brief Cargo ViewModel class
 * 
 */
class CargoViewModel : public QAbstractTableModel {
private:
    Q_OBJECT

    //! Collection of cargo for ViewModel
    QVector<cargo_entity> _data;

public:
    /**
     * @brief Construct a new Cargo View Model object
     * 
     * @param parent [ignored]
     */
    CargoViewModel(QObject *parent);
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

    /**
     * @brief Sets cargo collection
     * 
     * @param new_data 
     */
    void set_data(const QVector<cargo_entity> &new_data);
};

#endif // CARGOVIEWMODEL_H
