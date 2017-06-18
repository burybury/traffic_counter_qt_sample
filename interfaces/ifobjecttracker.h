#ifndef IF_OBJECTTRACKER_H
#define IF_OBJECTTRACKER_H

#include <blob-tracking/BlobTracker.h>

class IFObjectTracker
{
public:
    virtual cvb::CvTracks* getTracks() = 0;
    virtual ~IFObjectTracker() = default;
};

#endif // IF_OBJECTTRACKER_H
