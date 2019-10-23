/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject3\\x64\\Debug\\a.png", 1);
	namedWindow("red", WINDOW_NORMAL);
	for (int i = 0; i < img.rows; i++)
	{

		for (int j = 0; j < img.cols; j++)
		{
			if (!(img.at<Vec3b>(i, j)[0] <55 && img.at<Vec3b>(i, j)[1] < 55 && img.at<Vec3b>(i, j)[2] >100))
			{
				img.at<Vec3b>(i, j)[0] = 0;
				img.at<Vec3b>(i, j)[1] = 0;
				img.at<Vec3b>(i, j)[2] = 0;
			}
		}
	}
	imshow("red", img);
	waitKey(0);

}

*/