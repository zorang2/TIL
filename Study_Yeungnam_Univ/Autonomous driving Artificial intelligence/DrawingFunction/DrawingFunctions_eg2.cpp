//Drawing Function : rectangle(point or Rect) / circle / fillPoly

#if 0

#include <stdio.h>
#include <iostream>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;


int main(void) {

	int width = 1000;
	int height = 500;

	Mat img(height, width, CV_8UC3, Scalar(255, 255, 255));

	rectangle(img, Rect(50, 50, 100, 50), Scalar(0, 0, 255), 1); // Rect(start x, start y, width, height)
	rectangle(img, Point(50, 150), Point(150, 200), Scalar(0, 0, 255), -1); // pt1 = start point, pt2 = end point
	//rectangle(img, Rect(50, 150, 100, 50), Scalar(0, 0, 255), -1);
	circle(img, Point(300, 120), 30, Scalar(255, 0, 0), -1);
	circle(img, Point(300, 180), 30, Scalar(0, 0, 255), 1);

	Point trapezoid[1][4];
	trapezoid[0][0] = Point(width / 4, height / 4);
	trapezoid[0][1] = Point(width * 3 / 4, height / 4);
	trapezoid[0][2] = Point(width * 7 / 8, height / 2);
	trapezoid[0][3] = Point(width * 1 / 8, height / 2);

	const Point* ptr_trapezoid[1] = { trapezoid[0] };
	int number_of_points[] = { 4 };

	fillPoly(img, ptr_trapezoid, number_of_points, 1, Scalar(0, 0, 0), 0);

	imshow("img", img); //imshow('img2', img); 이렇게 쌍따옴표안하고 그냥 따옴표하면 안돌아간다.!!!
	waitKey(0);


}

#endif
