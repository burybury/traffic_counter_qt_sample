#ifndef FRAMEPROCESSINGPIPELINEFACTORY_H
#define FRAMEPROCESSINGPIPELINEFACTORY_H

#include <QDebug>
#include <QObject>
#include <QList>
#include <QStringList>
#include <frameprocessingpipeline.h>
#include <interfaces/ifprocessframe.h>

class FrameProcessingPipelineFactory : public QObject
{
    Q_OBJECT
private:
    QList<IFProcessFrame*> createModulesList();
public:
    explicit FrameProcessingPipelineFactory(QObject *parent = nullptr);
    FrameProcessingPipeline* createPipeline(QStringList urls);
signals:

public slots:
};

#endif // FRAMEPROCESSINGPIPELINEFACTORY_H
