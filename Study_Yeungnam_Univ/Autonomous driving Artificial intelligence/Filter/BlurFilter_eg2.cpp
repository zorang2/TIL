#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src = imread("rose.bmp", IMREAD_GRAYSCALE);
	Mat dst;

	imshow("src", src);

	for (int i = 3; i <= 9; i += 2) {
		blur(src, dst, Size(i,i));
		String display_str = format("Mean : %d x %d", i, i);
		putText(dst, display_str, Point(10, 30), 0, 1.0, Scalar(255), 1, 8);

		imshow("dst", dst);
		waitKey(0);
	}
	destroyAllWindows();
	return 0;
}

#endif