//HOUGH CIRCLES
/*
vector<Vec3f> circles;
int radius;
Point center;

HoughCircles( image, circles, CV_HOUGH_GRADIENT, 3, 150, 100, 20, 50, 80 );

for( size_t i = 0; i < circles.size(); i++ ) {
      center.x = cvRound(circles[i][0]);
      center.y = cvRound(circles[i][1]);
      radius = cvRound(circles[i][2]);
      // circle center
      circle( image, center, 3, Scalar(0,255,0), -1, 4, 0 );
      // circle outline
      circle( image, center, radius, Scalar(0,0,255), 3, 4, 0 );
    }

*/


//CONTOUR DETECTION
/*
vector<vector<Point> > contours;
vector<Vec4i> hierarchy;

findContours(image, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point(0,0));

for(int i=0; i<contours.size(); i++)
      drawContours(image, contours, i, Scalar(0), 4, 8);

*/


//CONVEX HULL
/*

//function
vector<Point> contoursConvexHull( vector<vector<Point> > contours )
{
    vector<Point> result;
    vector<Point> pts;
    for ( size_t i = 0; i< contours.size(); i++)
        for ( size_t j = 0; j< contours[i].size(); j++)
            pts.push_back(contours[i][j]);
    convexHull( pts, result );
    return result;
}


findContours(image, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point(0,0));

vector<Point> ConvexHullPoints =  contoursConvexHull(contours);
polylines( drawing, ConvexHullPoints, true, Scalar(0,0,255), 2 );

*/
