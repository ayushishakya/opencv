/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 1);
	namedWindow("mirror", WINDOW_NORMAL);
	int a;

	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols / 2; j++)
		{
			img.at<Vec3b>(i, j)[0] = img.at<Vec3b>(i, img.cols - j - 1)[0];
			img.at<Vec3b>(i, j)[1] = img.at<Vec3b>(i, img.cols - j - 1)[1];
			img.at<Vec3b>(i, j)[2] = img.at<Vec3b>(i, img.cols - j - 1)[2];
		}
	}

	imshow("mirror", img);
	waitKey(0);

}

*/