#ifndef APPCORE_H
#define APPCORE_H
#include<QVector>
#include <QObject>
#include <QtMultimedia/QMediaPlayer>
#include<QMediaMetaData>
#include <QTimer>
#include "playlist.h"
class AppCore : public QObject
{
    Q_OBJECT
public:
    explicit AppCore(QObject *parent = nullptr);

    void priviously();
    void setVolume();

signals:
    void durationChanged(int duration_);
    void controlLevelChanged(int volume);
    void sendLabelToQml(QString track);
    void allTracksToQml(unsigned int  allTracks);

public slots:

    void setDirectory(QString directory);
    int  getControlLevel() const;
    void setControlLevel(int _controlLevel);
    void setDuration(int duration);

    void play_track(QString track);
    void nextTrack();
    void prevTrack();
    void randomTrack();
    Playlist &getPlaylist();
    void play();
    void stop();




private slots:
    void setDuration1();//set duration for timer


private:

    Playlist  playlist;
    size_t curr_track;
    QMediaPlayer *player;
    int controlLevel;
    static int duration__;
    static size_t  temp;
    QTimer *timer;

};
#endif // APPCORE_H
