#ifndef IFTRACKEDDATASTREAM_H
#define IFTRACKEDDATASTREAM_H

#include <blob-tracking/BlobTracker.h>

class IFTrackedDataStream
{
public:
    virtual void streamData(cvb::CvTracks*) = 0;
    virtual ~IFTrackedDataStream() = default;
};


#endif // IFTRACKEDDATASTREAM_H
