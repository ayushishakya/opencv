/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	namedWindow("half", WINDOW_NORMAL);
	int val, a[256], sum2 = 0, k;
	Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 0);
	Mat copy(img.rows, img.cols, CV_8UC1, Scalar(255));
	for (int i = 0; i < 256; i++)
		a[i] = 0;
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			val = img.at<uchar>(i, j);
			a[val]++;
		}
	}
	int sum1 = img.rows*img.cols;

	for (k = 0; k < 256; k++)
	{
		sum2 += a[k];
		if (sum2 >= (sum1 / 2))
			break;
	}


	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			if (img.at<uchar>(i, j) <= k)
				copy.at<uchar>(i, j) = 0;
			else
				copy.at<uchar>(i, j) = 255;
		}
	}

	imshow("half", copy);
	waitKey(0);

}

*/