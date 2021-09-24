#if 0
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {

	using namespace cv;
	using namespace std;

	Point pt1;
	pt1.x = 5;
	pt1.y = 10;
	printf("Pt1: %d,%d\n", pt1.x, pt1.y);

	Point pt2(10, 30);

	printf("Pt2: %d,%d\n", pt2.x, pt2.y);

	Point pt3 = pt1 + pt2;
	printf("Pt3: %d,%d\n", pt3.x, pt3.y);
	
	Point pt4 = pt1 * 2;
	printf("Pt4: %d,%d\n", pt4.x, pt4.y);
	return 0;
}
#endif
