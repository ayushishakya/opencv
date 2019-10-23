
/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


using namespace cv;
using namespace std;

int isValid(Mat img, int x, int y)
{
	if ((x < 0) || (y < 0) || (x >= img.rows) || (y >= img.cols))
		return 0;
	else
		return 1;
}


Mat errosion(Mat a, Mat b)
{
	for (int i = 0; i < a.rows; i++)
	for (int j = 0; j < a.cols; j++)
	{
		if (a.at<uchar>(i, j) == 255)
		{
			int flag = 1;
			for (int k = -1; k <= 1; k++)
			for (int l = -1; l <= 1; l++)
			{
				if (isValid(a, i + k, j + l) == 1)
				if (a.at<uchar>(i + k, j + l) == 0)
					flag = 0;
			}

			if (flag == 0)
				b.at<uchar>(i, j) = 0;
		}
	}
	return b;
}

Mat dilation(Mat a, Mat b)
{
	for (int i = 0; i < a.rows; i++)
	for (int j = 0; j < a.cols; j++)
	{
		if (a.at<uchar>(i, j) == 0)
		{
			int flag = 1;
			for (int k = -1; k <= 1; k++)
			for (int l = -1; l <= 1; l++)
			{
				if (isValid(a, i + k, j + l) == 1)
				if (a.at<uchar>(i + k, j + l) == 255)
					flag = 0;
			}

			if (flag == 0)
				b.at<uchar>(i, j) = 255;
		}
	}
	return b;
}

int main()
{
	Mat x = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\filter3.png", 0);
	Mat y = x.clone();

	y = errosion(x, y);
	Mat f1 = y.clone();
	f1 = dilation(y, f1);

	namedWindow("Filter", WINDOW_AUTOSIZE);
	imshow("Filter", y);
	waitKey(0);

}
*/