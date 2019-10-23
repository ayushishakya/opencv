/*#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

using namespace cv;
using namespace std;

int main()
{
	Mat a(400, 400, CV_8UC1, Scalar(0));

	namedWindow("chess", WINDOW_AUTOSIZE);

	for (int i = 0; i < 400; i++)
	{
		for (int j = 0; j < 400; j++)
		{
			if ((i / 20) % 2 == 0)
			{
				if ((j / 20) % 2 == 0)
					a.at<uchar>(i, j) = 255;
			}
			else
			if ((j / 20) % 2 != 0)
				a.at<uchar>(i, j) = 255;


		}
	}

	imshow("chess", a);
	waitKey(0);
}
*/