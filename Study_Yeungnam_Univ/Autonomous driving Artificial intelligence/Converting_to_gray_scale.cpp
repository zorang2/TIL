#if 0
#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>

int main(void) {


	using namespace cv; //������ cv::imshow, cv::Mat,,,, �̷������� ��ߵ�. �׷� �κ��� ���ֱ����ؼ� ���� �����ع����°���.
	using namespace std; // std = standard, ���� ������ ���� (printf ��.)

	Mat color_img; //�ʱ�ȭ�� �ȵ�����?
	color_img = imread("lena.jpg"); //���⼭ �ʱ�ȭ�ϴ°Ŵ�.

	printf("\n\nrow:%d, col:%d\n\n", color_img.rows, color_img.cols);
	
	imshow("color_lena", color_img);

	Mat img_BGR[3]; // 3�迭�� ����
	split(color_img, img_BGR); // color_img�� �ɰ��� img_BGR�� �ִ´�

	imshow("lena_channel_B", img_BGR[0]); // opencv�� BGR�����ϱ�. 0���� B.
	imshow("lena_channel_G", img_BGR[1]);
	imshow("lena_channel_R", img_BGR[2]);

	Mat img_Gray = img_BGR[0] / 3 + img_BGR[1] / 3 + img_BGR[2] / 3;
	// �Ѳ����� ���ϰ� 1/3�����ʰ� ������ ���� 1/3�����ϰ� ���ϴ� ������?
	// >>>> 2^8 = 256. �� 0~255�� ������ �̹����� convert�ϴ� �������� �̻����� �� �ֱ� ������, �ִ��� �ȳ������� �̸��̸� ���� 1/3�ϴ°Ŵ�.
	imshow("lena_gray", img_Gray);

	waitKey(0);
	return 0;

}
#endif