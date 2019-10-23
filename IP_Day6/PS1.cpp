/*#include <stdio.h>
#include <iostream>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <opencv2\core\core.hpp>

using namespace cv;
using namespace std;

int hl = 7, hh = 20, sl = 125, sh = 230, vl = 225, vh = 253;
int flag = 0, countt1 = 0, countt2 = 0, centre = 0, num = 0;

void main()
{
	int fc = 0;
	VideoCapture cap("D:\\opencv\\new.mp4");

	Mat image;
	Mat binary(image.rows, image.cols, CV_8UC3);

	while (++fc)
	{
		if (fc > cap.get(CV_CAP_PROP_FRAME_COUNT))
			cout << "Score Team1=" << countt1 << "  Score Team2=" << countt2 << endl;
		
		cap.read(image);
	

		centre = 0; num = 0;
		cvtColor(image, image, CV_BGR2HSV);
		
		GaussianBlur(image, image, Size(9, 9), 2, 2);
		
		inRange(image, Scalar(hl, sl, vl), Scalar(hh, sh, vh), binary);

		for (int i = 0; i < 720; i++)
		for (int j = 0; j < 1120; j++)
		if (binary.at<uchar>(i, j) == 255)
		{
			centre += j; num++;
		}
		if (num != 0)
			centre /= num;
		cout << centre<<endl;
		
		if (centre < 63 && flag == 0 && num>10 && centre>2)
		{
			flag = 1; countt1++; cout << "Goal by Team1: " << countt1 << endl;
		}

		if (abs(centre - 386)<50)
			flag = 0;

		if (centre > 1070 && flag == 0 && num > 10)
		{
			flag = 1; countt2++;    cout << "Goal by Team2: " << countt2 << endl;
		}
		
		int e = waitKey(10);
		if (e == 13)
			break;
	}
	waitKey(0);
	}*/