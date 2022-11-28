#if 0

#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	float s = 2.f;

	float alpha = 1.f;

	Mat dst = s * src;
	
	Mat dst_alpha = src + (src - 128) * alpha;
	imshow("src", src);
	imshow("dst", dst);
	imshow("dst_alpha_ctrl", dst_alpha);

	waitKey(0);
	return 0;
}
#endif