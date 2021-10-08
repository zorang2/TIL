// Eg.4 results
// 주소복사가 아니라, Deep copy 예제이고, equlizeHist라는 opencv 내장 function 사용.
#if 0

#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat calcGrayHist(const Mat& img);

Mat drawGrayHistImage(const Mat& hist);

int main(void) {


	Mat src;
	src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	Mat dst(src.rows, src.cols, src.type());
	Mat hist_equalized_src;

	float alpha = 1;

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			//dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + 50);
			//dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) * 1.5);
			dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + ((src.at<uchar>(i, j) - 128 * alpha)));
		}
	}

	equalizeHist(src, hist_equalized_src);

	Mat hist_src = calcGrayHist(src);
	Mat hist_src_img = drawGrayHistImage(hist_src);

	Mat hist_dst = calcGrayHist(dst);
	Mat hist_dst_img = drawGrayHistImage(hist_dst);

	Mat hist_eq = calcGrayHist(hist_equalized_src);
	Mat hist_eq_img = drawGrayHistImage(hist_eq);

	imshow("src", src);
	imshow("srcHistogram", hist_src_img);

	imshow("dst", dst);
	imshow("dstHistogram", hist_dst_img);

	imshow("hist_equalization", hist_equalized_src);
	imshow("hist_eq_Histogram", hist_eq_img);

	waitKey(0);
	return 0;
}

Mat calcGrayHist(const Mat& img) {
	CV_Assert(img.type() == CV_8UC1);

	Mat hist;
	int channels[] = { 0 };
	int dims = 1;
	const int histSize[] = { 256 };
	float graylevel[] = { 0, 255 };
	const float* ranges[] = { graylevel };

	calcHist(&img,
		1,
		channels,
		noArray(),
		hist,
		dims,
		histSize,
		ranges
	);
	return hist;
}

Mat drawGrayHistImage(const Mat& hist) {
	CV_Assert(hist.type() == CV_32FC1);
	CV_Assert(hist.size() == Size(1, 256));

	double histMax;
	minMaxLoc(hist, 0, &histMax, 0, 0, noArray());

	printf("\n\n%f\n\n", histMax);

	int hist_box_width = 256;
	int hist_box_height = 200;

	Mat imgHist(hist_box_height, hist_box_width, CV_8UC3, Scalar(255, 255, 255));

	for (int i = 0; i < 256; i++) {
		line(imgHist,
			Point(i * (hist_box_width / 256), hist_box_height),
			Point(i * (hist_box_width / 256), hist_box_height - cvRound(hist.at<float>(i, 0) * hist_box_height / histMax)),
			Scalar(0, 0, 255),
			2);
	}
	return imgHist;
}

#endif


/* 내 코드
#include <stdio.h>
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

Mat calcGrayHist(const Mat& img);

Mat drawGrayHistImage(const Mat& hist);

int main(void) {


	Mat src;
	src = imread("hawkes.bmp", IMREAD_GRAYSCALE);

	Mat dst(src.rows, src.cols, src.type());
	Mat hist_equalized_src;

	float alpha = 5.1;

	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			//dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + 50);
			//dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) * 1.5);
			dst.at<uchar>(i, j) = saturate_cast<uchar>(src.at<uchar>(i, j) + ((src.at<uchar>(i, j) - 128 * alpha)));
		}
	}

	equalizeHist(src, hist_equalized_src);

	Mat hist_graph = calcGrayHist(src);
	Mat eq_hist_graph = drawHistogram(hist_equalized_src);

	Mat dst_hist_graph = drawHistogram(dst);

	imshow("src", src);
	imshow("srcHistogram", hist_graph);

	imshow("dst", dst);
	imshow("hist_dst_img", dst_hist_graph);

	imshow("hist_equalized_src", hist_equalized_src);
	imshow("hist_eq_img", eq_hist_graph);
	
	waitKey(0);
	return 0;
*/
