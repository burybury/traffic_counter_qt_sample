#include "cameracalibrator.h"

CameraCalibrator::CameraCalibrator()
{
    qDebug() << "CameraCalibrator()";
}

void CameraCalibrator::processFrame(cv::Mat &frame)
{
    frame.copyTo(tmpFrame);
    qDebug() << "CameraCalibrator::processFrame";
}
