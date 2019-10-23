/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int isValid(Mat img, int x, int y)
{
if ((x < 0) || (y < 0) || (x >= img.rows) || (y >= img.cols))
return 0;
else
return 1;
}

int main()
{
Mat a = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\veg.jpg", 0);
namedWindow("noise", WINDOW_AUTOSIZE);

int arr[25];

for (int i = 0; i < a.rows; i++)
{
for (int j = 0; j < a.cols; j++)
{
int count = 0;

for (int k = -2; k <= 2; k++)
for (int l = -2; l <= 2; l++)
if (isValid(a, i + k, j + l) == 1);
arr[count++] = a.at<uchar>(i + k, j + l);

sort(arr, arr + 25);
a.at<uchar>(i, j) = arr[13];
}
}

imshow("noise", a);
waitKey(0);
}*/