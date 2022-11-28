#if 0
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {


	using namespace cv; //원래는 cv::imshow, cv::Mat,,,, 이런식으로 써야됨. 그런 부분을 없애기위해서 먼저 선언해버리는거지.
	using namespace std; // std = standard, 위와 동일한 목적 (printf 등.)

	Mat color_img; //초기화가 안되있죠?
	color_img = imread("lena.jpg"); //여기서 초기화하는거다.

	printf("\n\nrow:%d, col:%d\n\n", color_img.rows, color_img.cols);
	
	imshow("color_lena", color_img);

	Mat img_BGR[3]; // 3배열로 만듦
	split(color_img, img_BGR); // color_img를 쪼개서 img_BGR로 넣는다

	imshow("lena_channel_B", img_BGR[0]); // opencv는 BGR순서니까. 0에는 B.
	imshow("lena_channel_G", img_BGR[1]);
	imshow("lena_channel_R", img_BGR[2]);

	Mat img_Gray = img_BGR[0] / 3 + img_BGR[1] / 3 + img_BGR[2] / 3;
	// 한꺼번에 더하고 1/3하지않고 일일이 각각 1/3부터하고 더하는 이유는?
	// >>>> 2^8 = 256. 즉 0~255를 넘으면 이미지를 convert하는 과정에서 이상해질 수 있기 때문에, 최대한 안넘으려고 미리미리 각각 1/3하는거다.
	imshow("lena_gray", img_Gray);

	waitKey(0);
	return 0;

}
#endif