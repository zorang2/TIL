#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	Mat neg_img = src.clone();

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			neg_img.at<uchar>(i, j) = 255 - src.at<uchar>(i, j);
		}
	}
	imshow("src", src);
	imshow("neg_img", neg_img);

	waitKey(0);
	return 0;
}
#endif