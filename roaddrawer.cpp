#include "roaddrawer.h"
#include <vector>

void RoadDrawer::debugPrintCorners()
{
   // for(unsigned int i = 0; i <4 ; i++)
    qDebug() <<  cornersX[0] << " " << cornersX[1] << " " << cornersX[2] << " " << cornersX[3] ;
    qDebug() <<  cornersY[0] << " " << cornersY[1] << " " << cornersY[2] << " " << cornersY[3] ;
}

void RoadDrawer::updatePolygonPoints()
{
    vectorAccess.lock();
    polygonPoints.clear();
    double ratio = 1;//(double(frame.cols)/400.0);

    polygonPoints.push_back(cv::Point2i((cornersX[0]*ratio), (cornersY[0]*ratio)));
    polygonPoints.push_back(cv::Point2i((cornersX[1]*ratio), (cornersY[1]*ratio)));
    polygonPoints.push_back(cv::Point2i((cornersX[2]*ratio), (cornersY[2]*ratio)));
    polygonPoints.push_back(cv::Point2i((cornersX[3]*ratio), (cornersY[3]*ratio)));
    vectorAccess.unlock();
    debugPrintCorners();
}

std::vector<cv::Point2i> &RoadDrawer::getPointsVector()
{
    return polygonPoints;
}

RoadDrawer::RoadDrawer(QObject *parent) : QObject(parent)
{
    selectedCorner = SelectedCorner::topleft;
    double ratio = 1;//(double(frame.cols)/400.0);

    polygonPoints.push_back(cv::Point2i((cornersX[0]*ratio), (cornersY[0]*ratio)));
    polygonPoints.push_back(cv::Point2i((cornersX[1]*ratio), (cornersY[1]*ratio)));
    polygonPoints.push_back(cv::Point2i((cornersX[2]*ratio), (cornersY[2]*ratio)));
    polygonPoints.push_back(cv::Point2i((cornersX[3]*ratio), (cornersY[3]*ratio)));
}

void
RoadDrawer::setSelectedCorner(int corner)
{

    selectedCorner = SelectedCorner(corner);
   // qDebug() << "selected corer passed to c++" << corner ;
}

void RoadDrawer::setCornerCoordinates(int x, int y)
{
    cornersX[selectedCorner] = x;
    cornersY[selectedCorner] = y;
    debugPrintCorners();
    updatePolygonPoints();
}

void RoadDrawer::saveRoadData()
{
    QFile file(roadCfgPath + "/road.cfg");
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);

    out.writeRawData(reinterpret_cast<char*>(cornersX),sizeof(int)*4);
    out.writeRawData(reinterpret_cast<char*>(cornersY),sizeof(int)*4);
    file.close();
    qDebug() << "road cfg saved";

}

void RoadDrawer::loadRoadData()
{
    QFile file(roadCfgPath + "/road.cfg");
    if(file.exists())
    {
        file.open(QIODevice::ReadOnly);
        if(file.isOpen())
        {
            QDataStream input(&file);
            input.readRawData(reinterpret_cast<char*>(cornersX),sizeof(int)*4);
            input.readRawData(reinterpret_cast<char*>(cornersY),sizeof(int)*4);
            file.close();
            qDebug() << "road cfg read";
            updatePolygonPoints();
        }
    }
    else
    {
        saveRoadData();
    }
}

void RoadDrawer::setRoadCfgPath(QUrl path)
{
    roadCfgPath = path.toLocalFile();
    qDebug() << " road cfg path set to " << roadCfgPath;
}


void RoadDrawer::drawRoad(cv::Mat &frame)
{
    if(!frame.empty()){
        cv::Mat frameOrignal;
        frame.copyTo(frameOrignal);
        vectorAccess.lock();
        const cv::Point* elementPoints[1] = { &polygonPoints[0] };
        //const cv::Point** cos{0};
        const int numberOfPoints = (int)polygonPoints.size();
        cv::fillPoly(frameOrignal,elementPoints,&numberOfPoints,1,cv::Scalar(255.0, 0.0, 0.0),8);
        vectorAccess.unlock();
        cv::addWeighted(frameOrignal, 0.5, frame,0.5, 0.0, frame);
    }

}

