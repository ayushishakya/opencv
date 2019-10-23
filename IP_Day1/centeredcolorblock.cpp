/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat a(400, 400, CV_8UC3, Scalar(0, 0, 0));
	namedWindow("block", WINDOW_AUTOSIZE);

	for (int i = 100; i<300; i++)
	{
		for (int j = 100; j<300; j++)
		{
			a.at<Vec3b>(i, j)[0] = 255;
			a.at<Vec3b>(i, j)[1] = 0;
			a.at<Vec3b>(i, j)[2] = 0;
		}
	}
	imshow("block", a);
	waitKey(0);
}

*/