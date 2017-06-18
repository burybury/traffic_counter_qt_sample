#ifndef CSVDATASTREAMER_H
#define CSVDATASTREAMER_H

#include <QDebug>
#include <interfaces/iftrackeddatastream.h>
#include <interfaces/ifobjecttracker.h>

class CSVDataStreamer :  public QObject, public IFTrackedDataStream
{
    Q_OBJECT
public:
    CSVDataStreamer();
// interface overrides
    void streamData(cvb::CvTracks*);
public slots:
    void notifyStreamData();
};

#endif // CSVDATASTREAMER_H
