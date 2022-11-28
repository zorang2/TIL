// histogram analysis
#if 0

#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat calcGrayHist(const Mat& img);

Mat drawGrayHistImage(const Mat& hist);

int main(void) {


	Mat src;
	src = imread("cameraman.jpg", IMREAD_GRAYSCALE);

	Mat hist = calcGrayHist(src);
	Mat hist_img = drawGrayHistImage(hist);

	imshow("src", src);
	imshow("srcHistogram", hist_img);

	waitKey();
	return 0;
}

Mat calcGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0, 255 };
	const float* ranges[] = { graylevel };

	calcHist(&img,
		1,
		channels,
		noArray(),
		hist,
		dims,
		histSize,
		ranges
	);
	return hist;
}

Mat drawGrayHistImage(const Mat& hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax, 0, 0, noArray());

	Mat imgHist(100, 256, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++) {
		line(imgHist,
			Point(i, 100),
			Point(i, 100 - cvRound(hist.at<float>(i, 0) * 100.f / histMax)),
			Scalar(0));
	}
	return imgHist;
}

#endif
