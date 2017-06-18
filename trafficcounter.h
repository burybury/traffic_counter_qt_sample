#ifndef TRAFFICCOUNTER_H
#define TRAFFICCOUNTER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <frameprocessingpipelinefactory.h>
#include <frameprocessingpipeline.h>
#include <frameprovider.h>
#include <roaddrawer.h>
#include <filemanager.h>
#include <pipelinethreading.h>

#include <typeinfo>

class TrafficCounter : public QObject
{
    Q_OBJECT
private:
    FrameProcessingPipelineFactory pipelineFactory{};
    FrameProvider *frameProvider{Q_NULLPTR};
    RoadDrawer roadDrawer{};
    FileManager videoFileManager{};
    PipelineThreading pipelineThreading{};
public:
    TrafficCounter(QObject *parent = nullptr);
    void initializeView(QQmlApplicationEngine& engine);
    Q_INVOKABLE void initializePipeline();
    ~TrafficCounter();
signals:

public slots:
};

#endif // TRAFFICCOUNTER_H
