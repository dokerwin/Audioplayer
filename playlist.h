#ifndef PLAYLIST_H
#define PLAYLIST_H
#include "datatracks.h"
#include "metadata.h"
#include <QString>
#include <vector>
#include<QSet>
#include <initializer_list>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include "loader.h"

class Playlist
{



public:
    Playlist(std::initializer_list<QString> &list);
    Playlist();
    ~Playlist();
    void fillPlaylist(QString directory); //fill playlist
    void fill(QString directory);

    void setFolders(QString folders); //set the folders with tracks
    bool dublicates(QString line);
    void savePlaylist();
    void savePlaylistPath();
    QString getPlayListFromFile();

    const MyModel &allTracks();
    const std::vector<QString> &allNameTracks();
    unsigned int  getCountTracks();
    MyModel &getModel();
    void init();


private:
    std::vector<QString> playlist;
    QSet<QString>folders;   
    std::vector<QString> tracks;

    unsigned int amount_tracks;
    MetaData * META;// DURING TRACK
    MyModel myData;
};



#endif // PLAYLIST_H
