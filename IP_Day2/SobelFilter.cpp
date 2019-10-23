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


int main()
{
	Mat a = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 0);
	Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));
	namedWindow("gFilter", WINDOW_AUTOSIZE);

	int arr[9] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
	int arr2[9] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
	int var = 156;
	createTrackbar("trackbar", "gFilter", &var, 255);

	while (1)
	{

		for (int i = 0; i < a.rows - 1; i++)
		{
			for (int j = 0; j < a.cols - 1; j++)
			{
				int count = 0, gy = 0, gx = 0;

				for (int k = -1; k <= 1; k++)
				for (int l = -1; l <= 1; l++)
				{
					if (isValid(a, i + k, j + l) == 1);
					{
						gx += arr[count] * a.at<uchar>(i + k, j + l);
						gy += arr2[count] * a.at<uchar>(i + k, j + l);
						count++;
					}
				}

				int g = sqrt(pow(abs(gx), 2) + pow(abs(gy), 2));

				if (g < var)
					b.at<uchar>(i, j) = 0;
				else
					b.at<uchar>(i, j) = 255;
			}
		}

		imshow("gFilter", b);
		int i = waitKey(50);
		if (i == 27)
			break;
	}
	imwrite("sobelflower.png", b);
}


*/