#include "roadhomography.h"

RoadHomography::RoadHomography()
{
    qDebug() <<  "RoadHomography()";
}

void RoadHomography::processFrame(cv::Mat &frame)
{
    frame.copyTo(tmpFrame);
    qDebug() <<  "RoadHomography::processFrame()";
}
