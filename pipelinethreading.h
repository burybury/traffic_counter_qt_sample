#ifndef PIPELINETHREADING_H
#define PIPELINETHREADING_H

#include <QObject>
#include <QFuture>
#include <QList>
#include <QtConcurrent/QtConcurrent>
#include <frameprocessingpipeline.h>

class PipelineThreading : public QThread
{
    Q_OBJECT
public:
    explicit PipelineThreading(QObject *parent = nullptr);
    void addPipelineForProcessing(FrameProcessingPipeline* pipeline);
    ~PipelineThreading();
    void run();
private:
    QList<FrameProcessingPipeline*> pipeLines{};
signals:

public slots:
};

#endif // PIPELINETHREADING_H
