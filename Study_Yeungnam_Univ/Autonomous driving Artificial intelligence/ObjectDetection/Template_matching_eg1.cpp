#if 0
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("circuit.bmp", IMREAD_COLOR);

	Mat template_img = imread("crystal.bmp", IMREAD_COLOR);

	Mat tmp_result, tmp_result_norm;
	matchTemplate(src, template_img, tmp_result, TM_CCOEFF_NORMED);
	normalize(tmp_result, tmp_result_norm, 0, 255, NORM_MINMAX, CV_8U);

	double maxv;
	Point maxloc;
	minMaxLoc(tmp_result, 0, &maxv, 0, &maxloc);

	rectangle(src, Rect(maxloc.x, maxloc.y, template_img.cols, template_img.rows), Scalar(0, 0, 255), 2);

	imshow("src", src);
	imshow("result_norm", tmp_result_norm);
	imshow("template_img", template_img);

	waitKey(0);
	return 0;

}


#endif
