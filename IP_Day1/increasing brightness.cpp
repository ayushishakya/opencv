/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat a = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\Chrysanthemum.jpg", 1);
	namedWindow("bright", WINDOW_AUTOSIZE);

	for (int i = 0; i<a.rows; i++)
	{
		for (int j = 0; j<a.cols; j++)
		{
			a.at<Vec3b>(i, j)[0] += 20;
			a.at<Vec3b>(i, j)[1] += 20;
			a.at<Vec3b>(i, j)[2] += 20;
		}
	}
	imshow("bright", a);
	waitKey(0);
}
*/