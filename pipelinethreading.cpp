#include "pipelinethreading.h"

PipelineThreading::PipelineThreading(QObject *parent) : QThread(parent)
{

}

void PipelineThreading::addPipelineForProcessing(FrameProcessingPipeline *pipeline)
{
    pipeLines.append(pipeline);
}

PipelineThreading::~PipelineThreading()
{
    for(FrameProcessingPipeline* pipeLine:pipeLines)
    {
        delete pipeLine;
    }
}

void PipelineThreading::run()
{
    bool processing{true};
    QList<QFuture<bool>> computationsList{};
    while(processing)
    {
        for(FrameProcessingPipeline* pipeLine:pipeLines)
        {
             computationsList.append(QtConcurrent::run(pipeLine,&FrameProcessingPipeline::process));
        }
        bool computationResult{true};
        for(QFuture<bool>& computation:computationsList){
            computation.waitForFinished();
            computationResult = computation.result();
            if(!computationResult)
            {
                // video feed ended stop processing
                processing = false;
            }
        }

    }
}
