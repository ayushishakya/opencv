/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<math.h>
#include<iostream>

using namespace cv;
using namespace std;

Mat f = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\ext1.png", 0);
Mat a;
int var1 = 134, var2 = 64;



int isValid(Mat &img, int x, int y)
{
if ((x < 0) || (y < 0) || (x >= img.rows) || (y >= img.cols))
return 0;
else
return 1;
}

int main()
{

namedWindow("obj", WINDOW_AUTOSIZE);
createTrackbar("track1", "obj", &var1, 255);
createTrackbar("track2", "obj", &var2, 255);

while (1)
{
	Canny(f, a, var1, var2);
	imshow("obj", a);

	char e = waitKey(20);
	if (e == 'a')
		break;
}
	int di = sqrt(pow(a.rows, 2) + pow(a.cols, 2)) + 1;
	Mat x(di * 2, 180, CV_8UC1, Scalar(0));


	for (int i = 0; i < a.rows; i++)
	for (int j = 0; j < a.cols; j++)
	{
		if (a.at<uchar>(i, j) == 255)
		for (int k = 0; k < 180; k++)
		{
			double v = (CV_PI*k) / 180.000;
			int d = j*cos(v) + i*sin(v) + di;
			if (x.at<uchar>(d, k) < 255)
				x.at<uchar>(d, k) += 3;
		}
	}

	namedWindow("graph", WINDOW_NORMAL);
	int var = 250;
	createTrackbar("track", "graph", &var, 255);
	
	while (1)
	{
		for (int i = 0; i < x.rows; i++)
		for (int j = 0; j < x.cols; j++)
		{

			if (x.at<uchar>(i, j) != 0)
			{
				int max = x.at<uchar>(i, j);

				for (int k = i - 4; k <= i + 4; k++)
				for (int l = j - 4; l <= j + 4; l++)
				if (isValid(a, k, j))
				if (x.at<uchar>(i, j)>max)
					max = x.at<uchar>(k, l);

				if (x.at<uchar>(i, j) == max && x.at<uchar>(i, j) > var)
					x.at<uchar>(i, j) = 255;
			}
			
		}

		imshow("graph", x);
		int e = waitKey(20);
		if (e == 13)
			break;
	}
	
	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));
	int check = 0;
	for (int l = 0; l < x.rows; l++)
	for (int k = 0; k < x.cols; k++)
	if (x.at<uchar>(l, k) == 255)
	{
		check++;
		
		for (int i = 0; i < b.rows; i++)
		for (int j = 0; j < b.cols; j++)
		{
			double p = CV_PI / 180.000;
			double v = p*k;
			int d = j*cos(v) + i*sin(v) + di;
		
			if ((d == l) && (k<80 || k>100))
			{
				cout << "hello" << endl;
				b.at<uchar>(i, j) = 255;
			}
		}
	
	}
	cout << check << endl;
	namedWindow("xx", WINDOW_AUTOSIZE);
	imshow("xx", b);
	waitKey(0);



}




*/