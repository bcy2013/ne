﻿#include "musicinfodata.h"

MusicInfoData::MusicInfoData(QObject *parent) : QObject(parent)
{
  m_strTitle="";
  m_strAlbumName="";
  m_strArtistName="";
  m_fMusicSize=0.0;
  m_iParentRow=-1;
  m_bIsFavourite=false;
}

MusicInfoData::MusicInfoData(QString title, QString artist, QTime duration, QString album, qreal musicSize)
{
    m_strTitle=title;
    m_strArtistName=artist;
    m_tDuration=duration;
    m_strAlbumName=album;
    m_fMusicSize=musicSize;
}

MusicInfoData::~MusicInfoData()
{

}

QString MusicInfoData::title() const
{
    return m_strTitle;
}

QString MusicInfoData::artistName() const
{
    return m_strArtistName;
}

QTime MusicInfoData::duration() const
{
    return m_tDuration;
}

QString MusicInfoData::albumName() const
{
    return m_strAlbumName;
}

qreal MusicInfoData::musicSize() const
{
    return m_fMusicSize;
}

bool MusicInfoData::isFavourite() const
{
    return m_bIsFavourite;
}

int MusicInfoData::parentRow() const
{
    return m_iParentRow;
}

QString MusicInfoData::path() const
{
    return m_strPath;
}

void MusicInfoData::setTitle(const QString &title)
{
    m_strTitle=title;
}

void MusicInfoData::setArtistName(const QString &artistName)
{
    m_strArtistName=artistName;
}

void MusicInfoData::setDuration(const QTime &duration)
{
    m_tDuration=duration;
}

void MusicInfoData::setAlbumName(const QString &albumName)
{
    m_strAlbumName=albumName;
}

void MusicInfoData::setMusicSize(const qreal &musicSize)
{
    m_fMusicSize=musicSize;
}

void MusicInfoData::setParentRow(const int &parentRow)
{
    m_iParentRow=parentRow;
}

void MusicInfoData::setIsFavourite(const bool &isFavourite)
{
    m_bIsFavourite=isFavourite;
}

void MusicInfoData::setPath(const QString &path)
{
    m_strPath=path;
}

QDataStream &operator<<(QDataStream &stream, const MusicInfoData *listData)
{
    return stream<<listData->title()<<listData->artistName()<<listData->duration()<<listData->albumName()<<listData->musicSize()<<listData->parentRow()<<listData->isFavourite()<<listData->path();
}

QDataStream &operator>>(QDataStream &stream, MusicInfoData *&listData)
{
    listData=new MusicInfoData();
    QString title;
    QString artist;
    QTime duration;
    QString album;
    qreal size;
    int parent;
    bool favourite;
    QString path;
    stream>>title>>artist>>duration>>album>>size>>parent>>favourite>>path;
    listData->setTitle(title);
    listData->setArtistName(artist);
    listData->setDuration(duration);
    listData->setAlbumName(album);
    listData->setMusicSize(size);
    listData->setParentRow(parent);
    listData->setIsFavourite(favourite);
    listData->setPath(path);
    return stream;
}
