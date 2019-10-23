/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{

	int a[256];
	Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 0);

	for (int i = 0; i < 256; i++)
		a[i] = 0;

	for (int i = 0; i < img.rows; i++)
	for (int j = 0; j < img.cols; j++)
	{
		int id = img.at<uchar>(i, j);
		a[id]++;
	}

	int max = a[0];
	for (int i = 0; i < 256; i++)
	if (max < a[i])
		max = a[i];

	Mat b(400, 256, CV_8UC1, Scalar(0));

	namedWindow("histogram", WINDOW_NORMAL);

	double f = 400.0000 / (double)max;

	for (int j = 0; j < 256; j++)
	for (int i = 0; i <= (int)(a[j] * f); i++)
		b.at<uchar>(i, j) = 255;


	imshow("histogram", b);
	waitKey(0);

}

*/