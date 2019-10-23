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
		
		for (int i = 0; i < img.rows/2; i++)
		{
			for (int j = 0; j < img.cols; j++)
			{
				img.at<Vec3b>(i, j)[0] = img.at<Vec3b>(img.rows - i - 1, j)[0];
				img.at<Vec3b>(i, j)[1] = img.at<Vec3b>(img.rows - i - 1, j)[1];
				img.at<Vec3b>(i, j)[2] = img.at<Vec3b>(img.rows - i - 1, j)[2];
			}
		}

		namedWindow("vid", WINDOW_AUTOSIZE);
		imshow("vid", img);
		int e = waitKey(5);
		if (e == 27)
			break;
	}
	}*/