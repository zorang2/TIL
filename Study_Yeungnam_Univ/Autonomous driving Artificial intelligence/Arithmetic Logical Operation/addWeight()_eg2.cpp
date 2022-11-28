// alpha beta곱해서 더하기 & for문 & addWeighted()사용

#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void) {
	
	Mat src1, src2;

	src1 = imread("airplane.bmp", IMREAD_COLOR);
	src2 = imread("field.bmp", IMREAD_COLOR);


	imshow("src1", src1);
	imshow("src2", src2);

	Mat dst1(src1.rows, src1.cols, src1.type());
	Mat dst2(src1.rows, src1.cols, src1.type());
	Mat dst3(src1.rows, src1.cols, src1.type());

	float alpha = 0.5;
	float beta = 0.5;
	
	dst1 = alpha * src1 + beta * src2;
	
	for (int i = 0; i < src1.rows; i++) {
		for (int j = 0; j < src1.cols; j++) {
			dst2.at<Vec3b>(i, j)[0] = saturate_cast<uchar>(alpha * src1.at<Vec3b>(i, j)[0] + beta * src2.at<Vec3b>(i, j)[0]);
			dst2.at<Vec3b>(i, j)[1] = saturate_cast<uchar>(alpha * src1.at<Vec3b>(i, j)[1] + beta * src2.at<Vec3b>(i, j)[1]);
			dst2.at<Vec3b>(i, j)[2] = saturate_cast<uchar>(alpha * src1.at<Vec3b>(i, j)[2] + beta * src2.at<Vec3b>(i, j)[2]);
		}
	}

	addWeighted(src1, alpha, src2, beta, 0, dst3);

	imshow("dst1", dst1);
	imshow("dst2", dst2);
	imshow("dst3", dst3);

	waitKey(0);
	return 0;
}


#endif
