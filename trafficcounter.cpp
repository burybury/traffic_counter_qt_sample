#include "trafficcounter.h"

TrafficCounter::TrafficCounter(QObject *parent) : QObject(parent)
{

}

void TrafficCounter::initializeView(QQmlApplicationEngine &engine)
{
    engine.rootContext()->setContextProperty("VideoFileManager",&videoFileManager);
    engine.rootContext()->setContextProperty("RoadDrawer",&roadDrawer);
    frameProvider = new FrameProvider();
    engine.rootContext()->setContextProperty("FrameProvider",frameProvider);
    engine.addImageProvider(QLatin1String("images"),frameProvider);
}

void TrafficCounter::initializePipeline()
{
    FrameProcessingPipeline* pipeLine = pipelineFactory.createPipeline(videoFileManager.getUrls());
    QObject::connect(pipeLine,&FrameProcessingPipeline::processingCycleEnd,frameProvider,&FrameProvider::updateQImages);
    pipeLine->preview();
    pipelineThreading.addPipelineForProcessing(pipeLine);
}

TrafficCounter::~TrafficCounter()
{
    // the allocated frameprovider wont be deleted here its managed by parent root context
}
