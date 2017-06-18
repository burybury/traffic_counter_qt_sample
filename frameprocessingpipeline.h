#ifndef FRAMEPROCESSINGPIPELINE_H
#define FRAMEPROCESSINGPIPELINE_H

#include <QDebug>
#include <QObject>
#include <QList>
#include <QStringList>
#include <interfaces/ifframefeed.h>
#include <interfaces/ifprocessframe.h>
#include <interfaces/ifobjecttracker.h>
#include <interfaces/iftrackeddatastream.h>
#include <typeinfo>

class FrameProcessingPipeline : public QObject
{
    Q_OBJECT
public:
    explicit FrameProcessingPipeline(QObject *parent = nullptr);
    FrameProcessingPipeline(IFFrameFeed* frameFeed,
                            QList<IFProcessFrame*> processingModules,
                            IFTrackedDataStream* dataStream);
    bool process();
    void preview();
    void replaceFrameProcessingModule(IFProcessFrame*);
    QList<IFProcessFrame*> &getModulesList();
    IFFrameFeed* getFrameFeed();
    bool isProcessing();
    void stopProcessing();
    ~FrameProcessingPipeline();
private:
    bool processing{false};
    IFFrameFeed* frameFeed{Q_NULLPTR};
    QList<IFProcessFrame*> processingModules{};
    IFTrackedDataStream* dataStream{Q_NULLPTR};
signals:
    void processingCycleEnd();
public slots:
};

#endif // FRAMEPROCESSINGPIPELINE_H
