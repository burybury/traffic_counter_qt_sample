#include "videofeed.h"

VideoFeed::VideoFeed(QStringList urlList)
{
    videoUrls = urlList;
    urlIterator = videoUrls.begin();
    capture.open((*urlIterator).toStdString());
}

bool VideoFeed::openNextVideo()
{
    urlIterator++;
    if(urlIterator == videoUrls.end())
    {
        // no more videos to open
        return false;
    }
    else
    {
        return capture.open((*urlIterator).toStdString());
    }
}


bool VideoFeed::retrieveFrame()
{
    if(capture.isOpened())
    {
        bool frameRetrieved = capture.read(currentFrame);
        if(!frameRetrieved)
        {
            if(openNextVideo())
            {
               return capture.read(currentFrame);
            }
            else
            {
                // no more videos
                return false;
            }
        }
        else
        {
            cv::resize(currentFrame,currentFrame,cv::Size(),0.5,0.5);
            return frameRetrieved;
        }
    }
    else
    {
        // capture did not open during initialize
        return false;
    }
}

cv::Mat VideoFeed::getFrame()
{
    return currentFrame;
}

VideoFeed::~VideoFeed()
{
    if(capture.isOpened())
    {
        capture.release();
    }
}
