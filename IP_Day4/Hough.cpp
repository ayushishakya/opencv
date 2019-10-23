/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<math.h>

using namespace cv;
using namespace std;

int main()
{
	Mat a = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\pentagon.png", 0);
	int di = sqrt(pow(a.rows, 2) + pow(a.cols, 2)) + 1;
	
	Mat x(di*2, 180, CV_8UC1, Scalar(0));
	
	//namedWindow("obj", WINDOW_NORMAL);

	for(int i = 0; i < a.rows; i++)
	for (int j = 0; j < a.cols; j++)
	{
		if (a.at<uchar>(i, j) == 255)
		{
			for (int k = 0; k < 180; k++)
			{
				double v = (CV_PI*k) / 180.000;
				int d = i*cos(v) + j*sin(v) +di;
				if(x.at<uchar>(d,k)<255)
				x.at<uchar>(d, k) +=3;
			}
		}
	}
	
	imshow("obj", x);
	waitKey(0);
}

*/