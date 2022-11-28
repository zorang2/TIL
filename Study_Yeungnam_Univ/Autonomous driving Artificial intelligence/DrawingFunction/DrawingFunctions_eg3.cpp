// DrawingFunction putText()
#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void) {
	
	int width = 1000;
	int height = 500;

	Mat img(height, width, CV_8UC3, Scalar(0, 0, 0));

	putText(img, "FONT_HERSHEY_SIMPLEX, Font scale = 1", Point(20, 50), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_PLAIN, Font scale = 1", Point(20, 100), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_DUPLEX, Font scale = 1", Point(20, 200), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_COMPLEX, Font scale = 1", Point(20, 300), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255));

	putText(img, "FONT_HERSHEY_COMPLEX_SMALL, Font scale = 1", Point(20, 400), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 255, 255));

	imshow("img", img);

	waitKey(0);
}
#endif