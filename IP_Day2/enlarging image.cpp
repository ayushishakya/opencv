/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat a = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 1);
	Mat b(a.rows * 4, a.cols * 4, CV_8UC3, Scalar(0, 0, 0));
	namedWindow("resized", WINDOW_AUTOSIZE);
	namedWindow("original", WINDOW_NORMAL);

	for (int i = 0; i < a.rows; i++)
	{
		for (int j = 0; j<a.cols; j++)
		{
			for (int m = 0; m < 2; m++)
			{
				for (int n = 0; n < 2; n++)
				{
					b.at<Vec3b>(i * 2 + m, j * 2 + n)[0] = a.at<Vec3b>(i, j)[0];
					b.at<Vec3b>(i * 2 + m, j * 2 + n)[1] = a.at<Vec3b>(i, j)[1];
					b.at<Vec3b>(i * 2 + m, j * 2 + n)[2] = a.at<Vec3b>(i, j)[2];
				}
			}
		}
	}

	imshow("original", a);
	imshow("resized", b);
	waitKey(0);
}
*/