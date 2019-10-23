#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/tracking.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv) {

VideoCapture cap(argv[1]);

Mat img,hist;
vector<Mat> channels;

cap.read(img);

while(cap.read(img)) {
  cvtColor(img, hist, CV_BGR2YCrCb); //change the color image from BGR to YCrCb format

  split(hist,channels); //split the image into channels

  equalizeHist(channels[0], channels[0]); //equalize histogram on the 1st channel (Y)

  imshow("Channel Y", channels[0]);

  merge(channels,hist); //merge 3 channels including the modified 1st channel into one image

  cvtColor(hist, hist, CV_YCrCb2BGR); //change the color image from YCrCb to BGR format (to display image properly)

  imshow("Original Image", img);
  imshow("Histogram Equalized", hist);

  if(waitKey(1)=='q')
    break;

}
cap.release();

}
