#ifndef ROADDRAWER_H
#define ROADDRAWER_H

#include <QObject>
#include <QDebug>
#include <QMutex>
#include <QFile>
#include <QUrl>
#include <QDataStream>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>


class RoadDrawer : public QObject
{
    Q_OBJECT
    int cornersX[4] = {50,100,100,50};
    int cornersY[4] = {50,50,100,100};
    int qimgW = 0;
    int qimgH = 0;

private:
    QMutex vectorAccess;
    enum SelectedCorner{
        topleft = 0,
        topright = 1,
        bottomleft = 2,
        bottomright = 3
    } selectedCorner;
    void debugPrintCorners();
    std::vector<cv::Point2i> polygonPoints;
    void updatePolygonPoints();
    QString roadCfgPath;
public:
    std::vector<cv::Point2i> &getPointsVector();
    explicit RoadDrawer(QObject *parent = 0);
    Q_INVOKABLE void setSelectedCorner(int corner);
    Q_INVOKABLE void setCornerCoordinates(int x, int y);
    Q_INVOKABLE void saveRoadData();
    Q_INVOKABLE void loadRoadData();
    Q_INVOKABLE void setRoadCfgPath(QUrl path);
    void drawRoad(cv::Mat& mat);
signals:

public slots:
};

#endif // ROADDRAWER_H
