#include "objecttracker.h"

ObjectTracker::ObjectTracker()
{
    qDebug() << "ObjectTracker()";
}

void ObjectTracker::processFrame(cv::Mat &frame)
{
    frame.copyTo(tmpFrame);
    qDebug() <<  "ObjectTracker::processFrame()";
}

cvb::CvTracks *ObjectTracker::getTracks()
{
    qDebug() <<  "ObjectTracker::getTracks()";
    return Q_NULLPTR;
}
