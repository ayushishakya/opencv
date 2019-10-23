/*#include "opencv2\core\core.hpp"
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\imgproc\imgproc.hpp"

using namespace cv;
using namespace std;


void main()
{
	VideoCapture cap("D:\\opencv\\task_buoy_3_minutes.avi");

	Mat img;
		
	while (cap.read(img))
	{
		Mat gray;
		cvtColor(img, gray, CV_BGR2GRAY);
	
		vector<Vec3f> circles;
		HoughCircles(gray, circles, CV_HOUGH_GRADIENT, 2, 30, 60, 75, 0, 0);
	
		for (size_t i = 0; i < circles.size(); i++)
		{
			Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
			int radius = cvRound(circles[i][2]);
			
			circle(img, center, 3, Scalar(0, 255, 0), -1, 8, 0);
			circle(img, center, radius, Scalar(0, 0, 255), 3, 8, 0);
		}

		imshow("circles", img);
		
		int e = waitKey(10);
		if (e == 13)
			break;
	}
	waitKey(0);
}

*/