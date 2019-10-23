#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/video/tracking.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv) {

int kernel;

cout<<"Enter kernel size :  \n";
cin>>kernel;

VideoCapture cap(argv[1]);

Mat img,blur_image, Gaussian_blur, median, out, bfilter;
vector<Mat> channels;

cap.read(img);

while(cap.read(img)) {

  //Homogeneous Smoothing :: Average of the neighbourhood of the pixel
  blur(img, blur_image, Size(kernel, kernel));

  //Bilateral Filter :: non-linear:edge preserving:noise reducing
  bilateralFilter(img, bfilter, kernel, 20, 20);

  //Gaussian Smoothing :: removes noise
  GaussianBlur(img, Gaussian_blur, Size(kernel, kernel), 0,0 );

  //Median Smoothing :: Preserves edges
  medianBlur(img, median, kernel);

  //Non-local Means Denoising :: details remain intact
  // Replacing color of a pixel with an average of the colors of similar pixels.
  fastNlMeansDenoisingColored(img, out, 3, 3, 7);


  //source image
  imshow("Original Image", img);

  //output images
  imshow("blur_image", blur_image);
  imshow("BILATERAL FILTER", bfilter);
  imshow("Gaussian_Blur", Gaussian_blur);
  imshow("MedianBlur", median);
  imshow("NlMeansDenoising", out);

  if(waitKey(1)=='q')
    break;

}
cap.release();

}
