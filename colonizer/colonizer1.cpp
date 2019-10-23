#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>
#include <algorithm>

using namespace cv;
using namespace std;

vector<Point> findCity(Mat image){
	
  cvtColor(image, image, COLOR_BGR2GRAY);
  vector<Point> city;
  vector<Vec3f> circles;
  Point center;

  HoughCircles( image, circles, CV_HOUGH_GRADIENT, 3, 100, 255, 30, 0, 100 );

  for( size_t i = 0; i < circles.size(); i++ ) {
    center.x = cvRound(circles[i][0]);
    center.y = cvRound(circles[i][1]);
      // circle center
    circle( image, center, 1, Scalar(255), -1, 1, 0 );
    circle( image, center, cvRound(circles[i][2]), Scalar(255), 1, 1, 0 );
    city.push_back(center);

  }

	imshow("LocatedCities", image);
	waitKey(0);
	return city;
}

int dist(Point a, Point b) {

	return floor(sqrt(pow(a.x-b.x, 2) + pow(a.y-b.y, 2)) + 0.5);
}

int totalDist(vector<Point> city){
	int sum = 0;
	for(int i=1; i<city.size(); i++)
		sum += dist(city[i], city[i-1]);

	return sum;
}

void optTour(vector<Point>& city) {
	for(int i=3; i<city.size(); i++) {
		if(dist(city[i-3], city[i-1]) < dist(city[i], city[i-2])) {
			int iTotal = totalDist(city);
			swap(city[i-2], city[i-1]);
			int fTotal = totalDist(city);

			if(fTotal > iTotal)
				swap(city[i-2], city[i-1]);
		}
	}
}

void nearestN(vector<Point>& city) {
	for(int i=1; i<city.size(); i++){
		int min = dist(city[i], city[i-1]);
		for(int j=i+1; j<city.size(); j++){
			if(min > dist(city[j], city[i-1]))
				swap(city[j], city[i]);
		}
	}
}


int main() {
	
	Mat frame = imread("/home/ayu/Pictures/planets.jpg");
	
	vector<Point> city = findCity(frame);
	int cost = totalDist(city);
	
	nearestN(city);
	optTour(city);
	
	cout<<"\nTotal distance = "<<cost<<"\nPath :  ";
	for(int i=0; i<city.size(); i++)
		cout<<city[i]<<", "<<dist(city[i], city[i+1])<<"\t";

	cout<<endl;
}