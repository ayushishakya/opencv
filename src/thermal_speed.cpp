#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "iostream"

using namespace cv;
using namespace std;

//calibration
int cal_obj_mm; //actual distance
int cal_obj_px; //distance in pixels

//float px_to_kph = float(cal_obj_mm/cal_obj_px * 0.0036);
float px_to_kph = 0.18;
time_t start, end;

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

  while(1) {
    // Start time
    //time(&start);

    //for(int j=0; j<5; j++)
      cap.read(img);

    // End Time
    //time(&end);

   // Time elapsed
    double seconds = 1489755.120; //difftime (end, start);

  //  cout<<"\nSeconds =  "<<seconds;
    int frames = cap.get(CV_CAP_PROP_FRAME_COUNT); // no. of frames

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
     vector<Point2f> prev_mc( contours.size() );

     for( int i = 0; i < contours.size(); i++ ) {
         ///eliminate small contours
         if( contourArea(Mat(contours[i])) < 500 )
            continue;

         if(frames > 1){
              prev_mc[i] = mc[i];
         }

         mu[i] = moments( contours[i], false );
        ///  Get the mass centers:
         mc[i] = Point2f( mu[i].m10/mu[i].m00 , mu[i].m01/mu[i].m00 );

         vector<Point2f> vel( contours.size() );

         vel[i].x = (mc[i].x - prev_mc[i].x)* px_to_kph /seconds;
         vel[i].y = (mc[i].y - prev_mc[i].y)* px_to_kph /seconds;

              cout<<"Velocity =  "<<vel[i]<<"kph\t";

         cout<<endl;
         drawContours( drawing, contours, i, Scalar(255), 1, 8, vector<Vec4i>(), 0, Point() );
      }

    imshow("Contour",drawing);

    if(waitKey(100)=='q')
      break;
   }
return 0;
}
