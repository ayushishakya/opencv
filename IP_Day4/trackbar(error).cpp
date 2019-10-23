/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
int b = 50, g = 50, r = 50, e=20;
namedWindow("grey", WINDOW_NORMAL);
createTrackbar("p", "grey", &b, 255);
createTrackbar("q", "grey", &g, 255);
createTrackbar("r", "grey", &r, 255);
createTrackbar("error", "grey", &e, 255);
Mat img = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\s.jpg", 1);
Mat a(img.rows, img.cols, CV_8UC1, Scalar(0));

while (1)
{
for (int i = 0; i < img.rows; i++)
{
	for (int j = 0; j < img.cols; j++)
	{
		int x = img.at<Vec3b>(i, j)[0];
		int y = img.at<Vec3b>(i, j)[1];
		int z = img.at<Vec3b>(i, j)[2];
		if (x<=(e + b) && x>=(b - e) && y>=(g - e) && y<=(g + e) && z>=(r - e) && z <= (r + e))
			a.at<uchar>(i, j) = 255;
		else
			a.at<uchar>(i, j) = 0;
	}
}
printf("%d", (b - e));
imshow("grey", a);
int l = waitKey(50);
if (l == 27)
break;
}

}

*/