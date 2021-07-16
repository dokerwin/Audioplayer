#include "AppCore.h"
#include<QDir>
#include <QDebug>
#include<QVector>
#include <QQuickView>

#include <QDateTime>

AppCore::AppCore(QObject* parent) : QObject(parent)
{
    curr_track =0;
    player = new QMediaPlayer;
    emit allTracksToQml(playlist.getModel().get_data().size());
}

void AppCore::play()
{

    player->setMedia(QUrl::fromLocalFile(playlist.getModel().get_data().at(curr_track).name));
    player->setVolume(50);
    qDebug()<<playlist.getModel().get_data().at(curr_track).name;

    player->play();

}

void AppCore::nextTrack()
{



    if(curr_track < playlist.getModel().get_data().size()-1){
        curr_track++;
    }
    emit sendLabelToQml(playlist.getModel().get_data().at(curr_track).name);
    stop();
    play();
}

void AppCore::randomTrack()
{

    if(curr_track < playlist.getModel().get_data().size()-1){
        curr_track = (qrand() % ((playlist.getModel().get_data().size() + 1) - 0) + 0);
    }

    emit sendLabelToQml(playlist.getModel().get_data().at(curr_track).name);
    stop();
    play();
}

Playlist &AppCore::getPlaylist()
{
    return playlist;
}



void AppCore::setDirectory(QString directory)
{

    playlist.fillPlaylist(directory);
    emit allTracksToQml(playlist.getCountTracks());



}

int AppCore::getControlLevel() const
{
    return controlLevel;
}

void AppCore::setControlLevel(int _controlLevel)
{
    qDebug()<< controlLevel;
    controlLevel = _controlLevel;
    player->setVolume(controlLevel);
    emit controlLevelChanged(controlLevel);

}

void AppCore::setDuration(int duration)
{



    int duration_in_seconds = (player->duration()/1000)%60;
  //  qDebug() << "duration = " << duration_in_seconds;
    duration_in_seconds = duration_in_seconds * duration/100;

    connect(player, &QMediaPlayer::durationChanged, this, [&](qint64 dur) {
        emit durationChanged(duration_in_seconds);
    });

}

void AppCore::play_track(const Data track)
{



}





void AppCore::stop()
{
    player->stop();
}


void AppCore::resive()
{
    play();
}




