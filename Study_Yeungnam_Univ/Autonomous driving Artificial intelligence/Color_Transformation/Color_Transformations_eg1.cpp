#if 0
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src, src_hsv, new_hsv;

	vector<Mat> src_hsv_channels; //create Mat array

	src = imread("colorful.jpg", IMREAD_COLOR);
	imshow("src", src);
	cvtColor(src, src_hsv, COLOR_BGR2HSV);

	split(src_hsv, src_hsv_channels);
	/*
	src_hsv_channels[0] = H     ->  H : 색조
	src_hsv_channels[1] = S     ->  S : 색상의 순도
	src_hsv_channels[2] = V     ->  V : 명암
	*/

	equalizeHist(src_hsv_channels[2], src_hsv_channels[2]);
	
	merge(src_hsv_channels, new_hsv);
	imshow("new_hsv", new_hsv);

	Mat hist_eq_V_img;
	cvtColor(new_hsv, hist_eq_V_img, COLOR_HSV2BGR);
	imshow("hist_eq_V_img", hist_eq_V_img);

	waitKey(0);
	return 0;

}

#endif