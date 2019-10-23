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


void kalmanfilter(Mat image, Mat frame, KalmanFilter KF, Mat_<float> measurement) {

    int count=0;
    int sum_x=0 ; int sum_y = 0;

    for(int i=200; i<frame.rows; i++)
      for(int j=0; j<frame.cols; j++) {

	if( frame.at<uchar>(i,j) == 255 ) {
		sum_x+=i;
		sum_y+=j;
		count++;
	}
     }

	if( !count ) return;

  // PREDICTION
    Mat prediction = KF.predict();

	// MEASUREMENT
    measurement(1)= (float)sum_x/count;
   	measurement(0) = (float)sum_y/count;

 	Point measPt(measurement(0), measurement(1));

  // CORRECTION
    Mat estimated = KF.correct(measurement);
 	  Point statePt(estimated.at<float>(0),estimated.at<float>(1));

       circle(image, measPt, 70,Scalar(0,0,255));
       circle(image, statePt, 70, Scalar(0,255,0));

	cout<<"Centre: "<<statePt<<"(estimated)\t"<<measPt<<"(measured)\n";
}


int main(int argc, char **argv) {

  static Mat_<float> measurement(2,1);
  static KalmanFilter KF(4, 2, 0);

  float dt = 1;

  KF.transitionMatrix = (Mat_<float>(4, 4) << 1,0,dt,0,   0,1,0,dt,  0,0,1,0,  0,0,0,1);

  setIdentity(KF.measurementMatrix);
  setIdentity(KF.processNoiseCov, Scalar::all(0.5));
  setIdentity(KF.measurementNoiseCov, Scalar::all(0.1));
  setIdentity(KF.errorCovPost, Scalar::all(1));

  VideoCapture cap(argv[1]);
  Mat img,hsv,grey;
  cap.read(img);
  VideoWriter out;
  out.open("/home/alpha/Videos/kf_out.avi", CV_FOURCC('D', 'I', 'V', 'X'), 120, img.size(), true);
  while(cap.read(img)) {

    cvtColor(img,hsv, COLOR_BGR2HSV);

    Mat frame = cfar(hsv, 8, 4, 0.01, 4);

    kalmanfilter(img, frame, KF, measurement);

    imshow("Frame", frame);
    imshow("Object", img);
      out.write(frame);
    if(waitKey(1)=='q')
      break;

  }
cap.release();
}
