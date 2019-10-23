#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv){

	VideoCapture cap(argv[1]);
	Mat image;

	namedWindow("color", WINDOW_AUTOSIZE);

	int thresh_l=87, thresh_h=132, low = 20, high = 50;
	createTrackbar("cr_high", "color", &thresh_h, 180);
	createTrackbar("cr_low", "color", &thresh_l, 180);
	//	createTrackbar("cb_low", "color", &low, 255);
		//	createTrackbar("cb_high", "color", &high, 255);

	while(cap.read(image)) {

		Mat out(image.size(), CV_8UC1, Scalar(0));

		cvtColor(image, image, COLOR_BGR2HSV);

		for(int i=0; i<image.rows; i++)
			for(int j=0; j<image.cols; j++)
				if(image.at<Vec3b>(i,j)[1] > thresh_l || image.at<Vec3b>(i,j)[1] < thresh_h) {
			//	if(image.at<Vec3b>(i,j)[2] > low || image.at<Vec3b>(i,j)[2] < high)
					out.at<Vec3b>(i,j) = 255;
				}
				cvtColor(image, image, COLOR_HSV2BGR);
	imshow("color", image);
	imshow("output", out);

	if(waitKey(5)=='q')
		break;
	}

	cap.release();
}
