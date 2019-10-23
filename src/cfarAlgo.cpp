#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/tracking.hpp"

using namespace cv;
using namespace std;


Mat cfar(Mat img, int num_train, int num_guard, float rate1, int block_size) {

Mat a(img.rows, img.cols, CV_8UC1, Scalar(0));

  int num_rows = a.rows-(a.rows%num_train);
  int num_cols = a.cols-(a.cols%num_train);
  int num_side = num_train/2;
  vector<Point> contours;

  double alpha1 =  pow(rate1, -1.00/num_train) -1 ;

  for(int i = num_side; i <= num_rows; i += block_size)
    for(int j = num_side; j <= num_cols; j += block_size) {

       int sum1 = 0, sum2 = 0;
       double thresh, p_noise;


       for(int x = i-(num_guard/2); x <= i+(num_guard/2)+1; x++)
         for(int y = j-(num_guard/2); y <= j+(num_guard/2)+1; y++)
           sum1 += img.at<Vec3b>(x,y)[0];

       for(int x = i-num_side; x <= i+num_side+1; x++)
         for(int y = j-num_side; y <= j+num_side+1; y++)
           sum2 += img.at<Vec3b>(x,y)[0];

       p_noise = fabs(sum1-sum2)/num_train;
       thresh = alpha1*p_noise;


       if( img.at<Vec3b>(i,j)[0] > thresh) {

         for(int k = i-block_size/2; k <= i+block_size/2; k++)
           for(int l = j-block_size/2; l <= j+block_size/2; l++)
           a.at<uchar>(k,l) = 255;
        }
    }

  return a;

}

int main(int argc, char **argv) {

  VideoCapture cap(argv[1]);
  Mat img,hsv;

  while(cap.read(img)) {

    cvtColor(img,hsv, COLOR_BGR2HSV);

    Mat frame = cfar(hsv, 8, 4, 0.01, 4);

    imshow("Frame", frame);
    imshow("Object", img);

    if(waitKey(1)=='q')
      break;
  }
cap.release();
}
