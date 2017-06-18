#ifndef OBJECTTRACKER_H
#define OBJECTTRACKER_H

#include <QDebug>
#include <interfaces/ifprocessframe.h>
#include <interfaces/ifobjecttracker.h>


class ObjectTracker : public QObject , public IFProcessFrame , public IFObjectTracker
{
    Q_OBJECT
public:
    ObjectTracker();

// interface overrides
    void processFrame(cv::Mat& frame);
    cvb::CvTracks* getTracks();
signals:
    void dataReady();
};

#endif // OBJECTTRACKER_H
