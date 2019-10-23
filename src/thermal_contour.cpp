#include <iostream>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int isValid(Mat img, int x, int y)
{
if ((x < 0) || (y < 0) || (x >= img.rows) || (y >= img.cols))
  return 0;
else
  return 1;
}

int main(int argc, char **argv) {

  Mat a = imread(argv[1]);
  Mat img(a.size(), CV_8UC1, Scalar(0));

  imshow("original", a);
  cvtColor(a, a, CV_RGB2YCrCb);

  Mat b(a.rows, a.cols, CV_8UC1, Scalar(0));

  int arr[49];
  int min;

  for (int i = 0; i < a.rows - 1; i++)
  for (int j = 0; j < a.cols - 1; j++)
  {
    int count = 0;
  //  min = a.at<Vec3b>(i,j)[2];

    for (int k = -3; k <= 3; k++)
      for (int l = -3; l <= 3; l++) {
        if (isValid(a, i + k, j + l) == 1)
          arr[count++] = a.at<Vec3b>(i + k, j + l)[2];
      }

//      sort(arr, arr + 48);
//      int th = arr[20] + 5;
    int th = *min_element(arr, arr+48) + 20;

    if ( th < a.at<Vec3b>(i,j)[2] )
      b.at<uchar>(i, j) = 0;
    else
      b.at<uchar>(i, j) = 255;

  }
  imshow("edge", b);

  waitKey(0);
}
