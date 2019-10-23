/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{

	int r[256], g[256], b[256];
	Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 1);

	for (int i = 0; i < 256; i++)
	{
		r[i] = 0;
		g[i] = 0;
		b[i] = 0;
	}

	for (int i = 0; i < img.rows; i++)
	for (int j = 0; j < img.cols; j++)
	{
		b[(img.at<Vec3b>(i, j)[0])]++;
		g[(img.at<Vec3b>(i, j)[1])]++;
		r[(img.at<Vec3b>(i, j)[2])]++;
	}

	int max1 = b[0], max2 = g[0], max3 = r[0];
	for (int i = 0; i < 256; i++)
	{
		if (max1 < b[i])
			max1 = b[i];

		if (max2 < g[i])
			max2 = g[i];

		if (max3 < r[i])
			max3 = r[i];

	}

	Mat blue(800, 256, CV_8UC1, Scalar(0));
	Mat green(800, 256, CV_8UC1, Scalar(0));
	Mat red(800, 256, CV_8UC1, Scalar(0));


	double f1 = 800.0000 / (double)max1;
	double f2 = 800.0000 / (double)max2;
	double f3 = 800.0000 / (double)max3;

	for (int j = 0; j < 256; j++)
	{
		for (int x = 0; x <= (int)(b[j] * f1); x++)
			blue.at<uchar>(x, j) = 255;

		for (int y = 0; y <= (int)(g[j] * f2); y++)
			green.at<uchar>(y, j) = 255;

		for (int z = 0; z <= (int)(r[j] * f3); z++)
			red.at<uchar>(z, j) = 255;

	}

	namedWindow("BLUE", WINDOW_NORMAL);
	namedWindow("GREEN", WINDOW_NORMAL);
	namedWindow("RED", WINDOW_NORMAL);

	imshow("BLUE", blue);
	imshow("GREEN", green);
	imshow("RED", red);
	waitKey(0);

}

*/