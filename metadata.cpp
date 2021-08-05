#include "metadata.h"
#include <QCoreApplication>

bool done =false;

MetaData::MetaData(QObject *parent)
{

    player = new QMediaPlayer;
    QMediaObject::connect(player, &QMediaPlayer::durationChanged, this, &MetaData::on_durationchanged);


}

MetaData *MetaData::getMetaData()
{
    if(metaData==nullptr){
          metaData = new MetaData();
      }
      return metaData;
}

qint64 MetaData::getDuration(QString track)
{


    done = false;
    player->setMedia(QUrl::fromLocalFile(track));

   while (done == false){

    QCoreApplication::processEvents();

   } //wait till the duration is read

    return duration;

}

void MetaData::on_durationchanged(qint64 dura)
{

    if(dura==0){

        duration = player->duration();
        return;
    }
   done = true;

   //int seconds=(dura/1000)%60;

   duration = dura;

}

QMediaPlayer *MetaData:: player= nullptr;
qint64 MetaData::duration=0;
bool MetaData::done=0;
MetaData * MetaData:: metaData = nullptr;
