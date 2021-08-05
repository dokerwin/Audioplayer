#include "loader.h"

QJsonDocument Loader::loadJson(QString fileName)
{
    QFile jsonFile(fileName);
    jsonFile.open(QFile::ReadOnly);
    return QJsonDocument().fromJson(jsonFile.readAll());
}



void Loader::playlist_toJobject()
{

    QJsonArray jsonArray;
    for(int i = 0; i < 20; i++) {
        QJsonObject jsonObject;
        jsonObject.insert("name", QString::number(i+1));
        jsonObject.insert("path", i+18);
        jsonObject.insert("duration", i+18);
        jsonArray.append(jsonObject);
    }



    QJsonDocument jsonDoc;
    jsonDoc.setArray(jsonArray);
    saveJson(jsonDoc,"output.json");



}

void Loader::saveJson(QJsonDocument document, QString fileName)
{
    QFile jsonFile(fileName);
    jsonFile.open(QFile::WriteOnly|QFile::Append);
    jsonFile.write(document.toJson());

}











void Loader::DeserPlaylist(QString track_json, QVector<Data> & m_data) //deserailization of playlist
{

    QJsonObject json_obj = loadJson(track_json).object();

    QJsonArray ptsArray = json_obj.value("tracks").toArray();
    foreach(const QJsonValue & val, ptsArray){
        QString x=val.toObject().value("name").toString();
        QString z=val.toObject().value("path").toString();
        double y=val.toObject().value("duration").toDouble();
        m_data.append(Data(x,z,y));
    }



     qDebug()<<ptsArray.size()<<"size";


}


Loader::Loader(QObject *parent) :
    QObject()
{


}
