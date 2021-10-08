// Histogram of Intensity transformed image Eg.2(main)
// 주소복사가 아니라, Deep copy 예제임.
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
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	Mat dst(src.rows, src.cols, src.type());

	float alpha = 1;

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			//dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + 50);
			//dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) * 1.5);
			dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + ((src.at<uchar>(i, j) - 128 * alpha)));
		}
	}

	Mat hist_src = calcGrayHist(src);
	Mat hist_src_img = drawGrayHistImage(hist_src);

	Mat hist_dst = calcGrayHist(dst);
	Mat hist_dst_img = drawGrayHistImage(hist_dst);

	imshow("src", src);
	imshow("srcHistogram", hist_src_img);

	imshow("dst", dst);
	imshow("dstHistogram", hist_dst_img);

	waitKey(0);
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
