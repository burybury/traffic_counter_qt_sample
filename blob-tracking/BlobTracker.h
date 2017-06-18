#pragma once

#include <iostream>
#include <opencv2\world.hpp>
#include <opencv2\highgui.hpp>

#include "blob.h"

//QT
#include <QDebug>

class BlobTracker
{
private:
	bool firstTime;

	uint debugTrack;
	uint debugBlob;
	uint showBlobMask;
	uint showOutput;

	cvb::CvTracks tracks;

	void saveConfig();

	void loadConfig();

public:
	BlobTracker();

	~BlobTracker();

	cv::Mat process(const cv::Mat img_mask);

	const cvb::CvTracks getTracks();

    void drawTracks(cv::Mat& mat);
};
