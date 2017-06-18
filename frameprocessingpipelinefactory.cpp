#include "frameprocessingpipelinefactory.h"
#include <videofeed.h>
#include <modules/cameracalibrator.h>
#include <modules/roadhomography.h>
#include <modules/objecttracker.h>
#include <modules/csvdatastreamer.h>

QList<IFProcessFrame *> FrameProcessingPipelineFactory::createModulesList()
{
    QList<IFProcessFrame*> modulesList;
    CameraCalibrator* cameraCalib = new CameraCalibrator();
    RoadHomography* homography = new RoadHomography();

    modulesList.append(cameraCalib);
    modulesList.append(homography);

    return modulesList;
}

FrameProcessingPipelineFactory::FrameProcessingPipelineFactory(QObject *parent) : QObject(parent)
{

}

FrameProcessingPipeline* FrameProcessingPipelineFactory::createPipeline(QStringList urls)
{
    VideoFeed* videoFeed = new VideoFeed(urls);
    CSVDataStreamer* dataStreamer = new CSVDataStreamer();
    ObjectTracker* objTracker = new ObjectTracker();
    QObject::connect(objTracker,&ObjectTracker::dataReady,dataStreamer,&CSVDataStreamer::notifyStreamData);
    QList<IFProcessFrame*> modulesList = createModulesList();
    modulesList.append(objTracker);
    FrameProcessingPipeline *pipeline = new FrameProcessingPipeline(videoFeed,modulesList,dataStreamer);
    return pipeline;
}
