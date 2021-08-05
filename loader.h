#ifndef LOADER_H
#define LOADER_H
#include "datatracks.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QVariant>
#include<QFile>
#include <QObject>
#include <QDebug>
#include <QJsonArray>

class Loader: public QObject
{
    Q_OBJECT
public:



    explicit Loader(QObject *parent = nullptr);

    static QJsonDocument loadJson(QString fileName);

    static void playlist_toJobject();

    static  void saveJson(QJsonDocument document, QString fileName);

    static  void DeserPlaylist(QString track_json, QVector<Data> & m_data);


};

#endif // LOADER_H
