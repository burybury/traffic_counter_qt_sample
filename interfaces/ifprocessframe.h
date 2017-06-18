#ifndef IFPROCESSFRAME_H
#define IFPROCESSFRAME_H

#include <opencv2/core.hpp>

class IFProcessFrame
{
protected:
    cv::Mat tmpFrame;
public:
    virtual void processFrame(cv::Mat& frame) = 0;
    virtual ~IFProcessFrame() = default;
    cv::Mat& getTmpFrame(){ return tmpFrame; }
};

#endif // IFPROCESSFRAME_H
