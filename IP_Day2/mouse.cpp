/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 1);

void Callbackfunc(int Event, int y, int x, int flags, void *userdata)
{
	if (Event == EVENT_LBUTTONDOWN)
	{
		printf("B = %d\n", img.at<Vec3b>(x, y)[0]);
		printf("G = %d\n", img.at<Vec3b>(x, y)[1]);
		printf("R = %d\n", img.at<Vec3b>(x, y)[2]);
	}
}

int main()
{
	imshow("win", img);
	setMouseCallback("win", Callbackfunc, NULL);
	waitKey(0);
}

*/