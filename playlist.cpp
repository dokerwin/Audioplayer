#include "playlist.h"
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <stdexcept> //for runtime_error




Playlist::Playlist(std::initializer_list<QString> &list) {
    playlist = list;
    amount_tracks = list.size();
}

Playlist::Playlist()
{
    META = MetaData::getMetaData();

    amount_tracks = 0;

    init();
}

Playlist::~Playlist()
{
    Loader::playlist_toJobject();
    savePlaylistPath();
}




void Playlist::fillPlaylist(QString directory) {

    directory.remove("file:///");


    QString temp = directory;

    if(!folders.contains(temp)){

        directory = directory +="/";
        qDebug()<<directory<< "was choosen";

        folders<< directory; //add to directory;

        fill(directory);
    }


    myData.refresh();

}

void Playlist::fill(QString directory)
{
    QDir *dir = new QDir(directory);
    QStringList filter;
    QList<QFileInfo> *fileInfo = new QList<QFileInfo>(dir->entryInfoList(filter));

    for (int i = 0; i < fileInfo->count(); i++)
    {
        if (fileInfo->at(i).fileName() != "." &&
                fileInfo->at(i).fileName() != "..") {
            if (fileInfo->at(i).fileName().contains("mp3")){
                amount_tracks++;
                myData.setData(fileInfo->at(i).fileName(),fileInfo->at(i).filePath(),META->getDuration(fileInfo->at(i).filePath()));
            }
        }
    }
}

void Playlist::setFolders(QString folders)
{
    folders.push_back(folders);
}



bool Playlist::dublicates(QString line) {

    QFile MyFile("folder_playlist.txt");
    MyFile.open(QIODevice::ReadWrite);
    QTextStream in(&MyFile);
    const QString content = in.readAll();

    if (!content.contains(line)) {
        return false;
    }


    MyFile.close();
    return true;
}

void Playlist::savePlaylist() {

    QFile file("folder_playlist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        throw std::runtime_error(
                "Error: Cant open the file for saving the playlist\n");

    QTextStream out(&file);
    for (auto &el : folders) {
        if (!dublicates(el)) {
            out << el << endl;
        }
    }

    file.close();
}

void Playlist::savePlaylistPath()
{

    QFile file("playlist.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        throw std::runtime_error(
                "Error: Cant open the file for saving the playlist\n");

    QTextStream out(&file);
    for (auto &el : myData.get_data()) {

        out << el.name << endl;
    }

    file.close();
}


QString Playlist::getPlayListFromFile() {



    QString backup;
    QFile file("playlist.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error(
                "Error: Cant open the file for reading the playlist\n");

    QTextStream in(&file);
    while (!in.atEnd()){
        QString a= in.readLine();
        folders<<a;
    }
    file.close();

    return backup;

}

const MyModel &Playlist::allTracks()
{
    return myData;
}



const std::vector<QString> &Playlist::allNameTracks()
{ return tracks; }


unsigned int Playlist::getCountTracks()
{

    //qDebug()<<amount_tracks;

    return amount_tracks;
}


MyModel & Playlist::getModel()
{
    return myData;
}



void Playlist::init()
{

     Loader::DeserPlaylist("output.json",myData.get_data());


}
