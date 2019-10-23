/*#include"opencv2/opencv.hpp"
#include"opencv2/core/core.hpp"
#include"opencv2/highgui/highgui.hpp"


using namespace std;
using namespace cv;

int isValid(Mat img, int x, int y)
{
if ((x < 0) || (y < 0) || (x >= img.rows) || (y >= img.cols))
return 0;
else
return 1;
}


int main()
{

	Mat img1;
	img1 = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\lisa.png", 0);
	int i, j, k, l; double c = 0.0;
	Mat img2(img1.rows, img1.cols, CV_8UC1, Scalar(0));
	int kernel = 3;

	for (i = 0; i < img1.rows; i++)
	{
		for (j = 0; j < img1.cols; j++)
		{
			c = 0;
			for (k = 2 - kernel; k < kernel - 1; k++)
			{
				for (l = 2 - kernel; l < kernel - 1; l++)
				{
				if (isValid(a, i + k, j + l) == 1);
					c += img1.at<uchar>(i + k, j + l);
                }

				img2.at<uchar>(i, j) = (int)c / 9;
			}
		}
	}
	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", img1);
	namedWindow("Filter", WINDOW_AUTOSIZE);
	imshow("Filter", img2);
	waitKey(0);
	return 0;
	}*/