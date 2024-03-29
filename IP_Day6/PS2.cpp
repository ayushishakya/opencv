/*#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

// Function Headers
void detectAndDisplay(Mat frame);

// Global variables
// Copy this file from opencv/data/haarscascades to target folder
string face_cascade_name = "C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\ComputerVision\\ComputerVision\\haarcascade_frontalface_alt.xml";
CascadeClassifier face_cascade;
string window_name = "Capture - Face detection";
int  flag=0,cnt=0;

// Function main
int main(void)
{
// Load the cascade
if (!face_cascade.load(face_cascade_name)){
printf("--(!)Error loading\n");
return (-1);
}
VideoCapture cap("C:\\Users\\sony\\Documents\\Visual Studio 2013\\Projects\\OpenCVProject1\\x64\\Debug\\new2.mp4");
Mat frame;
// Read the image file

while (1)
{
cap.read(frame);
if(cap.get(CV_CAP_PROP_FRAME_COUNT)%10==0)
detectAndDisplay(frame);
// Apply the classifier to the frame

int e = waitKey(15);
if (e == 13)
break;
}
if (flag == 1)
cnt++;
cout << "No. of people = " << cnt;
waitKey(0);
}

// Function detectAndDisplay
void detectAndDisplay(Mat frame)
{
std::vector<Rect> faces;
Mat frame_gray;
Mat crop;
Mat res;
Mat gray;

cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
equalizeHist(frame_gray, frame_gray);

// Detect faces
face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

// Set Region of Interest
cv::Rect roi_b;
cv::Rect roi_c;

size_t ic = 0; // ic is index of current element
int ac = 0; // ac is area of current element

size_t ib = 0; // ib is index of biggest element
int ab = 0; // ab is area of biggest element

for (ic = 0; ic < faces.size(); ic++) // Iterate through all current elements (detected faces)

{
roi_c.x = faces[ic].x;
roi_c.y = faces[ic].y;
roi_c.width = (faces[ic].width);
roi_c.height = (faces[ic].height);

ac = roi_c.width * roi_c.height; // Get the area of current element (detected face)


roi_b.x = faces[ib].x;
roi_b.y = faces[ib].y;
roi_b.width = (faces[ib].width);
roi_b.height = (faces[ib].height);

ab = roi_b.width * roi_b.height; // Get the area of biggest element, at beginning it is same as "current" element

if (ac > ab)
{
ib = ic;
roi_b.x = faces[ib].x;
roi_b.y = faces[ib].y;
roi_b.width = (faces[ib].width);
roi_b.height = (faces[ib].height);
}

crop = frame(roi_b);
resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR); // This will be needed later while saving images
cvtColor(crop, gray, CV_BGR2GRAY); // Convert cropped image to Grayscale

Point pt1(faces[ic].x, faces[ic].y); // Display detected faces on main window - live stream from camera
Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
if(faces.size()!=0)
flag=1;
else
{cnt++; flag=0;}
}



imshow("cap", frame);

}*/