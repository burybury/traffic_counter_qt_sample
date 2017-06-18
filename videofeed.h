#ifndef VIDEOFEED_H
#define VIDEOFEED_H

#include <QStringList>
#include <interfaces/ifframefeed.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class VideoFeed : public IFFrameFeed
{
private:
    cv::VideoCapture capture{};
    cv::Mat currentFrame{};
    QStringList videoUrls{};
    QStringList::Iterator urlIterator{videoUrls.begin()};

    bool openNextVideo();
public:
    VideoFeed(QStringList urlList);
    ~VideoFeed();
    // interface overrides
    bool retrieveFrame();
    cv::Mat getFrame();
};

#endif // VIDEOFEED_H
