/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"


using namespace cv;
using namespace std;

int main()
{
	VideoCapture vid(0);
	Mat img;

	while (1)
	{
		vid.read(img);
		Mat img2(img.rows, img.cols, CV_8UC1, Scalar(0));
		
		for (int i = 0; i < img.rows; i++)
		{
			for (int j = 0; j < img.cols; j++)
			{
				img2.at<uchar>(i, j) = 0.299*img.at<Vec3b>(i, j)[0] + 0.587*img.at<Vec3b>(i, j)[1] + 0.114*img.at<Vec3b>(i, j)[2];
			}
		}
		Mat x;
		Canny(img2, x, 20, 150);
		namedWindow("vid", WINDOW_AUTOSIZE);
		imshow("vid", x);
		int e = waitKey(20);
		if (e == 27)
			break;
	}
	}*/