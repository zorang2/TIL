#if 0
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat img1;
	//imshow("img1",img1);
	Mat img2(480, 640, CV_8UC1);
	//imshow("img2", img2);
	Mat img3(480, 640, CV_8UC3);
	//imshow("img3", img3);
	Mat img4(Size(640, 480), CV_8UC3);
	//imshow("img4", img4);
	Mat img5(480, 640, CV_8UC1, Scalar(128));
	//imshow("img5", img5);
	Mat img6(480, 640, CV_8UC3, Scalar(0, 0, 255));
	//imshow("img6", img6);

	waitKey();
	return 0;
}
#endif
