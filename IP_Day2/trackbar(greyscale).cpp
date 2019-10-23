/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int var = 120;
	namedWindow("grey", WINDOW_NORMAL);
	createTrackbar("p", "grey", &var, 255);

	while (1)
	{
		Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 0);

		for (int i = 0; i < img.rows; i++)
		{
			for (int j = 0; j < img.cols; j++)
			{
				if (img.at<uchar>(i, j) > var)
					img.at<uchar>(i, j) = 255;
				else
					img.at<uchar>(i, j) = 0;
			}
		}

		imshow("grey", img);
		int i = waitKey(50);
		if (i == 27)
			break;
	}
}
*/