#include "csvdatastreamer.h"

void CSVDataStreamer::notifyStreamData()
{
    qDebug() << "CSVDataStreamer::notifyStreamData()";
    IFObjectTracker* objTracker = dynamic_cast<IFObjectTracker*>(QObject::sender());
    cvb::CvTracks* tracks = objTracker->getTracks();
    streamData(tracks);
}

CSVDataStreamer::CSVDataStreamer()
{
    qDebug() << "CSVDataStreamer()";
}

void CSVDataStreamer::streamData(cvb::CvTracks *)
{
     qDebug() << "CSVDataStreamer::streamData()";
}
