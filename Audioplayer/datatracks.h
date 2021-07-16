/*************************************************************************
 *
 * Copyright (c) 2010-2019, Klaralvdalens Datakonsult AB (KDAB)
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>
#include <QColor>
#include <QMediaPlayer>
#include <QMediaMetaData>

struct Data {
    Data() {}

    bool operator == (const Data& lhs){ return this->name == lhs.name; }

    Data( const QString& name,  double duration )
        : name(name), duration(duration) {}
    QString name;
    double duration;


};

class MyModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole,
        DurationRole
    };

    explicit MyModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex& parent) const override;
    QVariant data( const QModelIndex& index, int role = Qt::DisplayRole ) const override;
    QHash<int, QByteArray> roleNames() const override;
    void setData(QString name, int duration);
    QVector<Data>&get_data();

public slots:
    void duplicateData(int row);
    void removeData(int row);



private: //members
    QVector< Data > m_data;

};

#endif // MYMODEL_H
