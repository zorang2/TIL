#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void) {

	Mat src1, src2, dst1, dst2, dst3, dst4;
	src1 = imread("lenna256.bmp", IMREAD_GRAYSCALE);
	src2 = imread("square.bmp", IMREAD_GRAYSCALE);

	imshow("src1", src1);
	imshow("src2", src2);

	bitwise_and(src1, src2, dst1);
	bitwise_or(src1, src2, dst2);
	bitwise_xor(src1, src2, dst3);
	bitwise_not(src1, dst4);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);
	imshow("dst4", dst4);

	waitKey(0);
	return 0;
}
#endif
