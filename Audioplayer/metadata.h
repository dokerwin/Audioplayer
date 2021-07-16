#ifndef METADATA_H
#define METADATA_H
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QObject>
#include <QCoreApplication>
class MetaData:public QObject
{
    Q_OBJECT
public:
    MetaData(MetaData & other)= delete;
    void operator=(const MetaData & other)= delete;
    static MetaData * getMetaData();
    qint64 getDuration(QString track);

private slots:

    static void on_durationchanged(qint64 duration);

private:


    explicit MetaData(QObject *parent = nullptr);
    static MetaData * metaData;
    static QMediaPlayer* player;
    static qint64 duration;
    static bool done;

};

#endif // METADATA_H
