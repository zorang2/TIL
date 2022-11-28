/*
예외처리 안 되어 있다고 오류뜨는 예제
*/


#if 1
#include "opencv2/opencv.hpp"
#include <stdio.h>
#include <iostream>

int main(void) {

	using namespace cv;
	using namespace std;

	Mat src;

	vector<Mat> src_rgb_channels;   //create Mat array

	src = imread("lena.jpg", IMREAD_COLOR);
	imshow("src", src);

	split(src, src_rgb_channels);
	
	/*
	src_rgb_channels[0] = B
	src_rgb_channels[1] = G
	src_rgb_channels[2] = R  <- OpenCV는 BGR순서다...!
	*/

	int B_channel_sum = 0;
	int G_channel_sum = 0;
	int R_channel_sum = 0;

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; i < src.cols; j++) {
			B_channel_sum += src_rgb_channels[0].at<uchar>(i, j);
			G_channel_sum += src_rgb_channels[1].at<uchar>(i, j);
			R_channel_sum += src_rgb_channels[2].at<uchar>(i, j);
		}
	}

	int B_channel_avg = 0;
	int G_channel_avg = 0;
	int R_channel_avg = 0;
	
	B_channel_avg = B_channel_sum / (src.rows * src.cols);
	G_channel_avg = G_channel_sum / (src.rows * src.cols);
	R_channel_avg = R_channel_sum / (src.rows * src.cols);
	
	//Mat dst1(src.rows)
	//Mat dst(src.rows, src.cols, src.type());
	Mat dst = src.clone();

	vector<Mat> dst_rgb_channels;
	split(dst, dst_rgb_channels);
	imshow("src", src);

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			dst_rgb_channels[0].at<uchar>(i, j) = saturate_cast<uchar>(src_rgb_channels[0].at<uchar>(i, j) * 128 / B_channel_avg);
			dst_rgb_channels[1].at<uchar>(i, j) = saturate_cast<uchar>(src_rgb_channels[1].at<uchar>(i, j) * 128 / G_channel_avg);
			dst_rgb_channels[2].at<uchar>(i, j) = saturate_cast<uchar>(src_rgb_channels[2].at<uchar>(i, j) * 128 / R_channel_avg);
		}
	}
	merge(dst_rgb_channels, dst);
	imshow("dst", dst);
	
	waitKey(0);
	return 0;

}
#endif