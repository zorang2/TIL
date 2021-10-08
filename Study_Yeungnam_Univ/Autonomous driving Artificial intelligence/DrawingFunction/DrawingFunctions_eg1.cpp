#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void) {

	int width = 800;
	int height = 400;

	Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));

	line(img, Point(50, 50), Point(200, 50), Scalar(0, 0, 255));
	line(img, Point(50, 100), Point(250, 100), Scalar(255, 0, 0), 3);

	arrowedLine(img, Point(25, 150), Point(300, 150), Scalar(0, 255, 0), 1);
	arrowedLine(img, Point(25, 250), Point(300, 250), Scalar(0, 255, 0), 2, 8, 0, 0.05);

	imshow("img", img);

	waitKey(0);

}
#endif
