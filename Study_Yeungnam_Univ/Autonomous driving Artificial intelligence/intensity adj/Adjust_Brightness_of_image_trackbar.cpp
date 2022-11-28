#if 0
#include <iostream>
#include <stdio.h>
#include "opencv2/opencv.hpp"

void on_brightness(int pos, void* userdata);

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("lena.jpg", IMREAD_GRAYSCALE);

	printf("\n\nrow:%d, cols:%d\n\n", src.rows, src.cols);

	Mat dst(src.rows, src.cols, src.type());

	namedWindow("dst");

	createTrackbar("Brightness", "dst", 0, 100, on_brightness, (void*)&src);
	on_brightness(0, (void*)&src);

	imshow("lena.original", src);
	waitKey(0);
	return 0;
}

void on_brightness(int pos, void* userdata) {
	using namespace cv;
	using namespace std;
	Mat src = *(Mat*)userdata;
	Mat dst = src + pos;
	imshow("dst", dst);

}
#endif
