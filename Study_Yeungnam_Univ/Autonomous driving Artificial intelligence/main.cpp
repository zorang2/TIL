#if 0
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {

	using namespace cv;
	using namespace std;

	//count<<"Hello OpenCV"<<CV_VERSION<<endl ;
	printf("hello opencv");

	Mat img;
	img = imread("lena.jpg");

	imshow("image_lena", img);

	waitKey();

	return 0;

}
#endif
