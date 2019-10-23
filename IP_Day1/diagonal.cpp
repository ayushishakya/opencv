/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat img(800, 800, CV_8UC3, Scalar(0, 0, 0));
	namedWindow("slant", WINDOW_AUTOSIZE);
	for (int i = 0; i < img.rows; i++)
	{
		for (int j = 0; j < img.cols; j++)
		{
			if (i>j)
				img.at<Vec3b>(i, j)[0] = 255;
			else
				img.at<Vec3b>(i, j)[1] = 155;
		}
	}
	imshow("slant", img);
	waitKey(0);

}
*/