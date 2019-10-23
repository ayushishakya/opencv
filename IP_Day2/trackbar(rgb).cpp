/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int var1 = 50, var2 = 50, var3 = 50;
	namedWindow("color", WINDOW_NORMAL);
	createTrackbar("p", "grey", &var1, 255);
	createTrackbar("q", "grey", &var2, 255);
	createTrackbar("r", "grey", &var3, 255);

	while (1)
	{
		Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\apple.png", 1);

		for (int i = 0; i < img.rows; i++)
		{
			for (int j = 0; j < img.cols; j++)
			{
				if (img.at<Vec3b>(i, j)[0] > var1)
					img.at<Vec3b>(i, j)[0] = 255;
				else
					img.at<Vec3b>(i, j)[0] = 0;

				if (img.at<Vec3b>(i, j)[1] > var2)
					img.at<Vec3b>(i, j)[1] = 255;
				else
					img.at<Vec3b>(i, j)[1] = 0;

				if (img.at<Vec3b>(i, j)[2] > var3)
					img.at<Vec3b>(i, j)[2] = 255;
				else
					img.at<Vec3b>(i, j)[2] = 0;

			}
		}

		imshow("color", img);
		int i = waitKey(50);
		if (i == 27)
			break;
	}
}

*/