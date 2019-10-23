/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;

int main()
{
	VideoCapture vid("C:\\Users\\Public\\Videos\\Sample Videos\\Wildlife.wmv");
	Mat img;

	while (1)
	{
		vid.read(img);
		int a = vid.get(CV_CAP_PROP_FRAME_COUNT);
		int b = vid.get(CV_CAP_PROP_POS_FRAMES);
		namedWindow("vid", WINDOW_AUTOSIZE);
		imshow("vid", img);
		cout << "Frame  count = " << a;
		cout << "\nFrame : " << b;
		int e = waitKey(5);
		if (e == 27)
			break;
	}
	}*/