#ifndef IFFRAMEFEED_H
#define IFFRAMEFEED_H

#include <opencv2/core.hpp>

class IFFrameFeed
{
public:
    virtual bool retrieveFrame() = 0;
    virtual cv::Mat getFrame() = 0;
    virtual ~IFFrameFeed() = default;
};

#endif // IFFRAMEFEED_H

