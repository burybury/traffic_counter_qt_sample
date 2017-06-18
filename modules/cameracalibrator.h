#ifndef CAMERACALIBRATOR_H
#define CAMERACALIBRATOR_H

#include <QDebug>
#include <interfaces/ifprocessframe.h>

class CameraCalibrator : public IFProcessFrame
{
public:
    CameraCalibrator();
// inteface overrides
    void processFrame(cv::Mat& frame);
};

#endif // CAMERACALIBRATOR_H
