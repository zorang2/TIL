#if 0
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src, src_hsv, new_hsv;

	src = imread("colorful.jpg", IMREAD_COLOR);
	imshow("src", src);

	cvtColor(src, src_hsv, COLOR_BGR2HSV);
	imshow("src_hsv", src_hsv);

	vector<Mat> src_hsv_channels;

	split(src_hsv, src_hsv_channels);
	/*
	src_hsv_channels[0] = H -> H = 색조
	src_hsv_channels[1] = S -> S = 색상의 순도
	src_hsv_channels[2] = V -> V = 명암
	*/

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			if (src_hsv_channels[0].at<uchar>(i, j) + 50 > 255) {
				src_hsv_channels[0].at<uchar>(i, j) = src_hsv_channels[0].at<uchar>(i, j) + 50 - 255;
			}
			else {
				src_hsv_channels[0].at<uchar>(i, j) = src_hsv_channels[0].at<uchar>(i, j) + 50;
			}
		}
	}

	merge(src_hsv_channels, new_hsv);

	Mat new_img;
	cvtColor(new_hsv, new_img, COLOR_HSV2BGR);
	imshow("hist_eq_V_img", new_img);

	waitKey(0);
	return 0;

}

#endif