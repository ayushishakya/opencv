#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

int main (int argc, char **argv)
 {
    Mat img,hsv,binary,binary1,imgToProcess;

    //Open the video
      VideoCapture cap(argv[1]);
      // Check if opened properly
          if(!cap.isOpened()){
        cout<<"Can't open video file.";
        return -1;
      }
  //    Mat frame, hsv;
    while(cap.read(img)) {

  //  img = imread(argv[1]);
    imshow("RGB",img);

    //convert RGB image into HSV image
    cvtColor(img, hsv, CV_BGR2HSV);
    //imshow("HSV",hsv);

    //get binary image
    inRange(hsv, Scalar(0, 85, 241), Scalar(18, 255, 255), binary);
    //imshow("binary", binary);
    inRange(hsv, Scalar(171, 0, 0), Scalar(255, 255, 255), binary1);


    //imshow("Binary1",binary1);
    add(binary1, binary, imgToProcess, noArray(), 8);

     //absdiff(binary1, binary, imgToProcess);
    //imshow("Binary2",imgToProcess);


    //find contours from binary image
    vector< vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours(imgToProcess, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0)); //find contours

    Mat drawing = Mat::zeros( imgToProcess.size(), CV_8UC1 );

     vector<Moments> mu(contours.size() );
     vector<Point2f> mc( contours.size() );

     for( int i = 0; i < contours.size(); i++ )
      {
        ///eliminate small contours
        if( contourArea(Mat(contours[i])) < 500 )
           continue;

       mu[i] = moments( contours[i], false );
       ///  Get the mass centers:
       mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 );


      cout<<"Center :  "<<mc[i]<<"\t";
      drawContours( drawing, contours, i, Scalar(255), 1, 8, vector<Vec4i>(), 0, Point() );
     }
  cout<<endl;
   imshow("Contour",drawing);

   if(waitKey(100)=='q')
     break;
  }
   return 0;
 }
