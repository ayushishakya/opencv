#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv) {

  VideoCapture cap(argv[1]);
  Mat image, hsv;

  int rlow=114, rhigh=143, blow=80, bhigh=120;

  while(cap.read(image)) {
   cvtColor(image, hsv, COLOR_BGR2YCrCb);
   Mat grey(image.rows, image.cols, CV_8UC1, Scalar(255));

   for(int i=0; i<hsv.rows; i++)
    for(int j=0; j<hsv.cols; j++)
		{
      if((hsv.at<Vec3b>(i,j)[1]<rlow || hsv.at<Vec3b>(i,j)[1]>rhigh) ||(hsv.at<Vec3b>(i,j)[2]<blow || hsv.at<Vec3b>(i,j)[2]>bhigh))
        grey.at<uchar>(i,j) = 0;
		}

  cvtColor(hsv, hsv, COLOR_YCrCb2BGR);
  imshow("Frame", grey);
  imshow("original", image);

    if(waitKey(100)=='q')
	break;
 }

}
