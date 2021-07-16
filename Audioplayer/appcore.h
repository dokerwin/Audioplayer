#ifndef APPCORE_H
#define APPCORE_H
#include<QVector>
#include <QObject>
#include <QtMultimedia/QMediaPlayer>
#include<QMediaMetaData>
#include "playlist.h"
class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = nullptr);
    void play();
    void priviously();
    void setVolume();

signals:
    void durationChanged(int duration);
    void controlLevelChanged(int volume);
    void sendLabelToQml(QString track);
    void allTracksToQml(unsigned int  allTracks);

public slots:

    void setDirectory(QString directory);
    int  getControlLevel() const;
    void setControlLevel(int _controlLevel);
    void setDuration(int duration);
    void play_track(Data track);
    void nextTrack();
    void randomTrack();
    Playlist &getPlaylist();
    void resive();
    void stop();



private:

    Playlist  playlist;
    size_t curr_track;
    QMediaPlayer *player;
    int controlLevel;


};
#endif // APPCORE_H
