/*
Compose imgs Using Only Logical Operation in opencv function(bitwise)
*/

#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src1, src2, src3, dst1, dst2, dst3, dst4, dst5, dst6;

	src1 = imread("airplane.bmp", IMREAD_COLOR);
	src2 = imread("mask_plane.bmp", IMREAD_COLOR);
	src3 = imread("field.bmp", IMREAD_COLOR);
	imshow("src1_airplane", src1);
	imshow("src2_mask_plane", src2);
	imshow("src3_field", src3);

	bitwise_not(src2, dst1);
	//imshow("src2반전", dst1);
	add(src1, dst1, dst2);
	//imshow("plane_with_field", dst2);
	bitwise_xor(dst1, dst2, dst3);
	//imshow("dst1 xor dst2", dst3);
	add(src2, src3, dst4);
	//imshow("src2 + src3", dst4);
	bitwise_xor(dst4, src2, dst5);
	//imshow("dd", dst5);
	add(dst5, dst3, dst6);
	imshow("plane_with_field", dst6);
	//add(0.5 * dst3, src3, dst4);
	//double alpha = 0.1;
	//double beta = 1;
	//addWeighted(dst3, alpha, src3, beta, 0, dst4);
	//imshow("dst3 + src3", dst4);

	//bitwise_and(src1, dst2, dst3);
	//bitwise_and(src3, dst3, dst4);
	//imshow("plane_with_field2", dst3);
	//imshow("plane_with_field3", dst4);

	waitKey(0);
	return 0;

}


#endif
