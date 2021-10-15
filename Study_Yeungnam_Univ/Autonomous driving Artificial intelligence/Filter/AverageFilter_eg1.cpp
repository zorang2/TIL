#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {

	using namespace std;
	using namespace cv;

	Mat src;
	src = imread("rose.bmp", IMREAD_GRAYSCALE);

	float data_3x3[] = {1.0 / 9, 1.0 / 9, 1.0 / 9,
						1.0 / 9, 1.0 / 9, 1.0 / 9,
						1.0 / 9, 1.0 / 9, 1.0 / 9 };
	Mat average_filter_3x3(3, 3, CV_32FC1, data_3x3);

	float data_5x5[] = { 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25,
						1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25,
						1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25,
						1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25,
						1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25, 1.0 / 25 };
	Mat average_filter_5x5(5, 5, CV_32FC1, data_5x5);

	Mat dst_3x3, dst_5x5;
	filter2D(src, dst_3x3, -1, average_filter_3x3, Point(-1, -1), 0);
	filter2D(src, dst_5x5, -1, average_filter_5x5, Point(-1, -1), 0);

	imshow("src", src);
	imshow("dst_3x3", dst_3x3);
	imshow("dst_5x5", dst_5x5);
	
	waitKey(0);
	return 0;
}
#endif
