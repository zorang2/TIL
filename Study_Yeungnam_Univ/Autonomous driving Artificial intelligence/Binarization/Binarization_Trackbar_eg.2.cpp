#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

void on_threshold(int pos, void* userdata);

	
int main(void) {

	Mat src;
	src = imread("neutrophils.png", IMREAD_GRAYSCALE);

	namedWindow("dst");
	createTrackbar("Threshold", "dst", 0, 255, on_threshold, (void*)&src);
	setTrackbarPos("Threshold", "dst", 128);

	imshow("src", src);

	waitKey(0);
	return 0;

}

void on_threshold(int pos, void* userdata) {
	Mat src = *(Mat*)userdata;
	Mat dst;
	threshold(src, dst, pos, 255, THRESH_BINARY);
	imshow("dst", dst);
}

#endif
