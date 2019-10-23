/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include<iostream>

using namespace cv;
using namespace std;


Mat a = imread("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\try.png", 1);
Mat x(a.rows, a.cols, CV_8UC3, Scalar(0,0,0));
int r, g, b;

int isValid(Mat img, int x, int y)
{
if ((x < 0) || (y < 0) || (x >= img.rows) || (y >= img.cols))
return 0;
else
return 1;
}

void DFS_visit(int i, int j)
{

x.at<Vec3b>(i, j)[0] = 0;
x.at<Vec3b>(i, j)[1] = 0;
x.at<Vec3b>(i, j)[2] = 255;

for (int k = i-1; k <= i+1; k++)
for (int l = j-1; l <=j+ 1; l++)
{
if (isValid(a,k,l))
if ((x.at<Vec3b>(k,l)[2]==0) && (a.at<Vec3b>(k, l)[2] == r)&&(a.at<Vec3b>(k, l)[1] == g)&&(a.at<Vec3b>(k, l)[0] == b))
DFS_visit(k, l);
}

}

void Callbackfunc(int Event, int l, int k, int flags, void *userdata)
{
if (Event == EVENT_LBUTTONDOWN)
{

b=a.at<Vec3b>(k, l)[0] ;
g=a.at<Vec3b>(k, l)[1] ;
r=a.at<Vec3b>(k, l)[2] ;
cout << b << "\t" << g << "\t" << r << endl;
DFS_visit(k,l);
for (int i = 0; i < x.rows; i++)
for (int j = 0; j < x.cols; j++)
if (x.at<Vec3b>(i, j)[2] != 0)
{
a.at<Vec3b>(i, j)[0] = 0;
a.at<Vec3b>(i, j)[1] = 0;
a.at<Vec3b>(i, j)[2] = 255;
}

imshow("obj", a);
}
}



int main()
{
namedWindow("obj", WINDOW_NORMAL);
imshow("obj", a);

setMouseCallback("obj", Callbackfunc, NULL);
waitKey(0);
}
*/