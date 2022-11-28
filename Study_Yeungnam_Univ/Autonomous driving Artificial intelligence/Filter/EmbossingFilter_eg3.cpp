#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("rose.bmp", IMREAD_GRAYSCALE);

	float data_embossing_3x3[]{ -1.0, -1.0, 0.0,
								-1.0, 0.0, 1.0,
								0.0, 1.0, 1.0 };
	Mat embossing_3x3(3, 3, CV_32FC1, data_embossing_3x3);

	float data_embossing_5x5[]{ 1.0, 0.0, 0.0, 0.0, 0.0,
								0.0, 1.0, 0.0, 0.0, 0.0,
								0.0, 0.0, 0.0, 0.0, 0.0,
								0.0, 0.0, 0.0, -1.0, 0.0,
								0.0, 0.0, 0.0, 0.0, -1.0 };
	Mat embossing_5x5(5, 5, CV_32FC1, data_embossing_5x5);

	Mat dst_embossing_3x3, dst_embossing_5x5;

	filter2D(src, dst_embossing_3x3, -1, embossing_3x3, Point(-1, -1), 128);
	filter2D(src, dst_embossing_5x5, -1, embossing_5x5, Point(-1, -1), 128);

	imshow("src", src);
	imshow("dst_embossing_3x3", dst_embossing_3x3);
	imshow("dst_embossing_5x5", dst_embossing_5x5);

	waitKey(0);
	return 0;

}
#endif