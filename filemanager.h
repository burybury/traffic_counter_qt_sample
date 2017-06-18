#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QUrl>
#include <QDebug>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>

class FileManager : public QObject
{
    Q_OBJECT
    QStringList urlsOfVideos;
public:
    explicit FileManager(QObject *parent = 0);
    Q_INVOKABLE void populateUrls(QUrl dir);
    QStringList& getUrls();
signals:
    void urlsNotEmpty();
};

#endif // FILEMANAGER_H
