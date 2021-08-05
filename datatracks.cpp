/*************************************************************************
 *
 * Copyright (c) 2010-2019, Klaralvdalens Datakonsult AB (KDAB)
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "datatracks.h"
#include <QByteArray>
#include <QTimer>
#include <cstdlib>

MyModel::MyModel(QObject *parent) :
    QAbstractListModel(parent)
{



}

int MyModel::rowCount( const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return m_data.count();
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if ( !index.isValid() )
        return QVariant();

    const Data &data = m_data.at(index.row());
    if ( role == NameRole ){
        return data.name;
    }

    else if ( role == DurationRole )
        return data.duration;
    else if ( role == PathRole )
        return data.path;
    else
        return QVariant();
}

//--> slide
QHash<int, QByteArray> MyModel::roleNames() const
{
    static QHash<int, QByteArray> mapping {
        {NameRole, "name"},
        {PathRole, "path"},
        {DurationRole, "duration"}
    };
    return mapping;
}

void MyModel::setData(QString name,QString path, int duration)
{

    m_data << Data(name,path,duration);

}

 QVector<Data> &MyModel::get_data()
{
    return m_data;
}
//<-- slide

void MyModel::duplicateData(int row)
{
    if (row < 0 || row >= m_data.count())
        return;

    const Data data = m_data[row];
    const int rowOfInsert = row + 1;

    beginInsertRows(QModelIndex(), rowOfInsert, rowOfInsert);
    m_data.insert(rowOfInsert, data);
    endInsertRows();
}

void MyModel::removeData(int row)
{
    if (row < 0 || row >= m_data.count())
        return;

    beginRemoveRows(QModelIndex(), row, row);
    m_data.removeAt(row);
    endRemoveRows();
}

void MyModel::refresh()
{

    const int count = m_data.size();
    const QModelIndex startIndex = index(0, 0);
    const QModelIndex endIndex   = index(count, 0);



    beginInsertRows(QModelIndex(), 0, m_data.size());

    endInsertRows();

    // ...but only the population field
    emit dataChanged(startIndex, endIndex, QVector<int>() << NameRole);

    qDebug()<<"refresh";
}








