#if 0
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src;

	src = imread("rainfall.jpg", IMREAD_GRAYSCALE);

	imshow("src", src);

	Mat color_map;

	applyColorMap(src, color_map, COLORMAP_JET);

	imshow("color_map", color_map);

	waitKey(0);
	return 0;

}

#endif