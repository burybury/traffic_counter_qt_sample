#include "filemanager.h"

FileManager::FileManager(QObject *parent) : QObject(parent)
{
    urlsOfVideos = QStringList();
}

void FileManager::populateUrls(QUrl url)
{
    QDir qdir(url.toLocalFile());
    qdir.setNameFilters(QStringList()<<"*.mp4"<<"*.MP4");
    qDebug() << "Selected url" << url.toLocalFile();
    if(qdir.entryList().empty())
    {
        qDebug() << "entry list empty";
    }
    QFileInfoList fileInfoList = qdir.entryInfoList();
    foreach (QFileInfo fInfo, fileInfoList) {
         qDebug() << fInfo.absoluteFilePath();
         urlsOfVideos.append(QString(fInfo.absoluteFilePath()));
    }
    if(urlsOfVideos.empty())
    {
        qDebug() << "urls empty";
    }
    else
    {
        emit urlsNotEmpty();
    }
}

QStringList &FileManager::getUrls()
{
    return urlsOfVideos;
}


