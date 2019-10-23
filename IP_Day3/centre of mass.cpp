/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;

Mat a = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\try.png", 0);

int isValid(Mat img, int x, int y)
{
	if ((x < 0) || (y < 0) || (x >= img.rows) || (y >= img.cols))
		return 0;
	else
		return 1;
}

void DFS_visit(int i, int j, int cnt, Mat &x)
{
	x.at<uchar>(i, j) = 250/cnt;

	for (int k = -1; k <= 1; k++)
	for (int l = -1; l <= 1; l++)
	{
		if (isValid(a, i + k, j + l))
		if ((!x.at<uchar>(i + k, j + l)) && a.at<uchar>(i + k, j + l) == 255)
			DFS_visit(i + k, l + j, cnt, x);
	}

}

int main()
{
	Mat x(a.rows, a.cols, CV_8UC1, Scalar(0));

	int count = 1;
	for (int i = 0; i < a.rows; i++)
	for (int j = 0; j < a.cols; j++)
	{
		if ((a.at<uchar>(i, j) == 255) && !x.at<uchar>(i, j))
		{
			DFS_visit(i, j, count, x);
			count++;
		}
	}
	   
  float sumx[3] = { 0, 0, 0 }, sumy[3] = { 0, 0, 0 }, pix[3] = { 0, 0, 0 };

	for (int i = 0; i < x.rows; i++)
	for (int j = 0; j < x.cols; j++)
	{
		if (x.at<uchar>(i, j))
		{
			int val = (250/x.at<uchar>(i, j))-1;
			sumx[val] += i;
			sumy[val] += j;
			pix[val]++;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		x.at<uchar>((int)(sumx[i] / pix[i]), (int)(sumy[i] / pix[i])) = 255;
		cout << "COM: " << (int)(sumx[i] / pix[i]) << "," << (int)(sumy[i] / pix[i]) << endl;
	}
	
	namedWindow("bin", WINDOW_AUTOSIZE);
	imshow("bin", x);
	waitKey(0);


	}*/