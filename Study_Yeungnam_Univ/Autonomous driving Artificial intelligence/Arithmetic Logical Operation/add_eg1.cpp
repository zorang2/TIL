/*
여기서 3번 run을 시켜서 비교해보라.

첫 번째, dst = src2 + src1만 활성화
두 번째, dst = src2 + src1 & for문 활성화
세 번째, add만 활성화

for문 속에 0.5라는 값은 이미지의 비율을 정하는 것이고, 나중에 add문에서의 weight(가중치) 역할을 한다.

************  Error 유의사항 : 두 번째 run에서 dst = src2 + src1; 문을 활성화시키지않으면 Error가 난다. ***********
 >> 왜? : src2, src1은 airplane, field의 이미지로 범위가 정해져있는데 dst는 범위가 define되어 있지 않기 때문에.
*/
#if 0
#include <iostream>
#include <stdio.h>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(void) {
	
	Mat src1, src2, dst;
	src1 = imread("airplane.bmp", IMREAD_GRAYSCALE);
	src2 = imread("field.bmp", IMREAD_GRAYSCALE);

	imshow("src1", src1);
	imshow("src2", src2);

	dst = src2 + src1;

	/*
	for (int i = 0; i < src1.rows; i++) {
		for (int j = 0; j < src1.cols; j++) {
			dst.at<uchar>(i, j) = saturate_cast<uchar>(0.5 * src1.at<uchar>(i, j) + 0.5 * src2.at<uchar>(i, j));
		}
	}
	*/

	//add(src1, src2, dst);

	imshow("src1+src2", dst);

	waitKey(0);
	return 0;

}

#endif
