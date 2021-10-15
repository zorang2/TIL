#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src;
	src = imread("rose.bmp", IMREAD_GRAYSCALE);
	imshow("src", src);

	Mat dst;
	for (int sigma = 1; sigma <= 5; sigma++) {
		GaussianBlur(src, dst, Size(), (double)sigma);

		String display_str = format("sigma = %d", sigma);
		putText(dst, display_str, Point(10, 30), 0, 1.0, Scalar(255), 1, 8);
		imshow("dst", dst);
		waitKey(0);
	}
	destroyAllWindows();
	return 0;
}

#endif
