#ifndef ROADHOMOGRAPHY_H
#define ROADHOMOGRAPHY_H

#include <QDebug>
#include <interfaces/ifprocessframe.h>

class RoadHomography : public IFProcessFrame
{
public:
    RoadHomography();

// interface overrides
    void processFrame(cv::Mat& frame);
};

#endif // ROADHOMOGRAPHY_H
