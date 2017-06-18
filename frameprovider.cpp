#include "frameprovider.h"



FrameProvider::FrameProvider(QObject *parent) : QObject(parent), QQuickImageProvider(QQuickImageProvider::Pixmap)
{

}

QPixmap FrameProvider::requestPixmap(const QString &id, QSize*, const QSize&)
{
    if(id.at(0) == QChar('o'))
    {
        QPixmap pixmap = (QPixmap::fromImage(QImage(orginalQImage)));
        if(!pixmap.isNull())
        {
             return pixmap;
        }

    }
    return   QPixmap(20,20);
}

void FrameProvider::updateQImages()
{
    FrameProcessingPipeline* pipeLine = static_cast<FrameProcessingPipeline*>(QObject::sender());
    cv::Mat orginalMat = pipeLine->getFrameFeed()->getFrame();
    orginalQImage = QImage((unsigned char*) orginalMat.data,
                            orginalMat.cols,
                            orginalMat.rows,
                            QImage::Format_RGB888
                            );
    emit qimagesReady();
}



