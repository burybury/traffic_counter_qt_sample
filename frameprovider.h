#ifndef FRAMEPROVIDER_H
#define FRAMEPROVIDER_H
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include <interfaces/ifprocessframe.h>
#include <frameprocessingpipeline.h>

#include <QObject>
#include <QQuickImageProvider>
#include <QColor>
#include <QPixmap>
#include <QSize>
#include <QImage>
#include <QObject>
#include <QDebug>
#include <QMutex>

class FrameProvider : public QObject, public QQuickImageProvider
{
    Q_OBJECT
public:
    FrameProvider(QObject* parent = 0);
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
private:
    QMutex imageMutex;
    QImage  orginalQImage;
    QImage  imageRoadTracks;
signals:
    void qimagesReady();
public slots:
    void updateQImages();
};

#endif // FRAMEPROVIDER_H
