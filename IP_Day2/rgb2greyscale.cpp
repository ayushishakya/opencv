/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	int b;
	Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 1);
	Mat img2(img.rows, img.cols, CV_8UC3, Scalar(0));
	namedWindow("grey", WINDOW_NORMAL);
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			img2.at<uchar>(i, j) = 0.299*img.at<Vec3b>(i, j)[0] + 0.587*img.at<Vec3b>(i, j)[1] + 0.114*img.at<Vec3b>(i, j)[2];
		}
	}
	imshow("grey", img2);
	waitKey(0);

}

*/