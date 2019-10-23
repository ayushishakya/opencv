#include <math.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int isValid(Mat img, int x, int y) {
  if( x < 0 || y < 0 || x >= img.rows || y >= img.cols)
      return 0;

  return 1;
}

int main(int argc, char **argv) {

  int channel, fac, n;
  cout<<"Enter channel number : ";
  cin>>channel;
  cout<<"Kernel Size (nXn): ";
  cin>>n;
  cout<<"Reduction factor : ";
  cin>>fac;

  VideoCapture cap(argv[1]);
  Mat a, in;

  while(cap.read(in)) {

    resize(in, a, Size(in.rows/fac, in.cols/fac), 0, 0, INTER_LINEAR);
    Mat gray(a.rows, a.cols, CV_8UC1, Scalar(0));

    medianBlur(a,a,21);
    imshow("original", a);

    //traversing each and every pixel
    for(int i=2; i<a.rows; i++)
      for(int j=2; j<a.cols; j++) {

        long long int sum=0, sq=0;

        // nXn kernel
        for(int x = i-(n/2); x <= i+(n/2) ; x++)
          for(int y = j-(n/2); y <= j+(n/2) ; y++)
            //checking validity of pixel
            if(isValid(a, x, y))
              sum += a.at<Vec3b>(x,y)[channel] ;

        //  cout<<sum/(n*n)<<"\t";
          if(a.at<Vec3b>(i,j)[channel] < sum/(n*n))
            gray.at<uchar>(i,j) = 0;
          else
            gray.at<uchar>(i,j) = 255;

      }

    imshow("segm_object", gray);

    cout<<"\n FPS: "<<cap.get(CAP_PROP_FPS);

    if(waitKey(100)=='q')
      break;
  }

}
