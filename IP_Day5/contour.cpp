/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <vector>

using namespace cv;
using namespace std;

int main()
{
	Mat img1 = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\apple.png", 0);
	Mat img2;
	Canny(img1, img2, 30, 120);
	vector<vector<Point> > cont;
	vector<Vec4i> h;
	findContours(img2, cont, h, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE);
	Mat z(img2.rows, img2.cols, CV_8UC1, Scalar(0));
	for (int i = 0; i < cont.size(); i++)
	for (int j = 0; j < cont[i].size(); j++)
	{
		z.at<uchar>(cont[i][j].y, cont[i][j].x) = 255;
	}

	imshow("canny", z);
	waitKey(0);
}
*/