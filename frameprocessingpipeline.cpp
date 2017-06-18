#include "frameprocessingpipeline.h"

FrameProcessingPipeline::FrameProcessingPipeline(QObject *parent) : QObject(parent)
{

}

FrameProcessingPipeline::~FrameProcessingPipeline()
{
    delete frameFeed;
    foreach (auto* module, processingModules) {

        delete module;
    }
    delete dataStream;
}

FrameProcessingPipeline::FrameProcessingPipeline(IFFrameFeed *frameFeed, QList<IFProcessFrame *> processingModules, IFTrackedDataStream *dataStream)
: frameFeed(frameFeed), dataStream(dataStream)
{
    foreach (auto* module, processingModules) {
        this->processingModules.append(module);

    }
    qDebug() << "FrameProcessingPipeline()";
}

bool FrameProcessingPipeline::process()
{
    qDebug() << "FrameProcessingPipeline::process()";
    processing = true;
    if(frameFeed->retrieveFrame())
    {
        cv::Mat orginalFrame = frameFeed->getFrame();
        cv::Mat tmp = orginalFrame;
        for(IFProcessFrame* processingModule:processingModules){
            processingModule->processFrame(tmp);

        }
        emit processingCycleEnd();
    }
    return true;
}

void FrameProcessingPipeline::preview()
{
    for(unsigned int i = 0; i <10; i ++){
        frameFeed->retrieveFrame();
        emit processingCycleEnd();
    }
}

QList<IFProcessFrame *> &FrameProcessingPipeline::getModulesList()
{
    return processingModules;
}

IFFrameFeed *FrameProcessingPipeline::getFrameFeed()
{
    return frameFeed;
}

bool FrameProcessingPipeline::isProcessing()
{
    return processing;
}

void FrameProcessingPipeline::stopProcessing()
{
    qDebug() << "FrameProcessingPipeline::stopProcessing()";
    processing = false;
}

