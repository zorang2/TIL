#if 0

#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {

	using namespace std;
	using namespace cv;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE); //IMREAD_GRAYSCALE => always convert image to the single channel gray scale image

	printf("\n\nrow:%d, col:%d\n\n", src.rows, src.cols);

	imshow("lena_original", src);
	
	Mat dst = src + 100;

	imshow("dst", dst);

	waitKey(0);
	return 0;
}

#endif