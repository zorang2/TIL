#if 0
#include <iostream>
#include <stdio.h>
#include "opencv2/opencv.hpp"

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	float s = 2.f;
	Mat dst = s * src;
	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}

#endif