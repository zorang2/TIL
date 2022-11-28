#if 0
#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

int main(void) {
	using namespace cv;
	using namespace std;

	Mat src, blur, La_input, La_abs;

	src = imread("moon.jpg", IMREAD_GRAYSCALE);

	GaussianBlur(src, blur, Size(5, 5), 0, 0, 4);

	Laplacian(blur, La_input, CV_16S, 1, 1, 0);

	convertScaleAbs(La_input, La_abs);
	Mat dst;
	dst = src + La_abs;

	imshow("src", src);
	imshow("blur", blur);
	imshow("La_src", La_input);
	imshow("La_src_abs", La_abs);
	imshow("dst", dst);

	waitKey(0);
	destroyAllWindows();
	
	return 0;
}

#endif
