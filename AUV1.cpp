/*#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"

using namespace cv;
using namespace std;

int bl = 0, bh = 80, gl = 70, gh = 165, rl = 250, rh = 255;

void main()
{
	VideoCapture cap("D:\\opencv\\task_marker_20_seconds.avi");

	Mat image;
	Mat binary(image.rows, image.cols, CV_8UC3);

	while (cap.read(image))
	{
		inRange(image, Scalar(bl, gl, rl), Scalar(bh, gh, rh), binary);

		imshow("bin", binary);
		int e = waitKey(10);
		if (e == 13)
			break;
	}
	waitKey(0);
}

*/