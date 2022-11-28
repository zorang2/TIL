#if 0
#include <stdio.h>;
#include <iostream>;
#include "opencv2/opencv.hpp"

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	printf("\n\n rows : %d, cols : %d \n\n", src.rows, src.cols);

	Mat dst(src.rows, src.cols, src.type());
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			dst.at<uchar>(i, j) = src.at<uchar>(i, j);
		}
	}

	Mat dst2 = dst.clone();
	for (int i = 0; i < dst2.rows / 2; i++) {
		for (int j = 0; j < dst2.cols / 4; j++) {
			//dst2.at<uchar>(i, j) = (dst2.at<uchar>(i, j) + 100);
			dst2.at<uchar>(i, j) = saturate_cast<uchar>(dst2.at<uchar>(i, j) + 100);
		}
	}

	imshow("lena_original", src);
	imshow("dst", dst);
	imshow("dst2", dst2);

	waitKey(0);
	return 0;
}
#endif