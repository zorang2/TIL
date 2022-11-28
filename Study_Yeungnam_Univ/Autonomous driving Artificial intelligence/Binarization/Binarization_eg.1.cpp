#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("neutrophils.png", IMREAD_GRAYSCALE);

	Mat dst;
	threshold(src, dst, 200, 255, THRESH_BINARY);

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;

}

#endif
