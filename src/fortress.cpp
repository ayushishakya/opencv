#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

RNG rng(12345);

float dist(Point a, Point b) {
  return sqrt(pow(a.x - b.x, 2)+ pow(a.y - b.y, 2))
}

int main(int argc, char **argv) {
  Mat img = imread(argv[1]);
  Mat a;

  cvtColor(img, a, CV_BGR2GRAY);

  //To invert the color-scheme.
  bitwise_not(a, a);

 vector<vector<Point> > contours;
 vector<Vec4i> hierarchy;

 /// Find contours
 findContours( a, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE );

 /// Draw contours
 for( int i = 0; i< contours.size(); i++ )
    {
      cout<<"\nCountour ::  "<<i<<"\t"<<contours[i].size()<<endl;

      for(int j=0; j<contours[i].size(); j++)
        cout<<contours[i][j]<<"\t";

      Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( img, contours, i, color, 2, 8, hierarchy, 0, Point() );
    }

 /// Show in a window
 namedWindow( "Contours", CV_WINDOW_AUTOSIZE );
 imshow( "Contours", img );

  waitKey(0);
 return 0;
}
