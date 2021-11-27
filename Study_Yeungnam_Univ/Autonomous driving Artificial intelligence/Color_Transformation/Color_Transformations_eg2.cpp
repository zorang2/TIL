#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src, src_hsv, new_hsv;

	vector<Mat> src_hsv_channels;

	src = imread("colorful.jpg", IMREAD_COLOR);
	imshow("scr", src);
	cvtColor(src, src_hsv, COLOR_BGR2HSV);

	split(src_hsv, src_hsv_channels);
	/*
	src_hsv_channels[0] = H  ->  H = ����
	src_hsv_channels[1] = S  ->  S = ������ ����
	src_hsv_channels[2] = V  ->  V = ���
	*/
	
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			if ((src_hsv_channels[0].at<uchar>(i, j) > 9) && (src_hsv_channels[0].at<uchar>(i, j) < 23)) { // when 9 < H < 23 (orange color range)
				src_hsv_channels[1].at<uchar>(i, j) = src_hsv_channels[1].at<uchar>(i, j);
			}
			else {
				src_hsv_channels[1].at<uchar>(i, j) = 0; // ������ ������ �ƴ� ������ ������ 0���� ����.
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