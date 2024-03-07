#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

///////////////  Basic Functions  //////////////////////

void main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

	cvtColor(img, imgGray, COLOR_BGR2GRAY);
	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	Canny(imgBlur, imgCanny, 25, 75);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	Mat kernel_e = getStructuringElement(MORPH_RECT, Size(3, 3));
	dilate(imgCanny, imgDil, kernel);
	erode(imgDil, imgErode, kernel_e);

	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilation", imgDil);
	imshow("Image Erode", imgErode);
	waitKey(0);
}


/*
* Takeaways:
* 1. If the Canny edge detector is applied on the original image or the grayscaled image, there are more edges that are being detected(noisy/psuedo edges).
* 2. The blurring process helps to reduce the noisy edges
* 3. Experimenting with keranel size for dilation:increasing the kernel size increses the edge thickness and vice versa
* 4. Experimenting with keranel size for Erosion:increasing the kernel size reduces the edge thickness and vice versa.
	If your kernal size for erosion is greater than the size for dilation then the oputput image just gets some white dots. 
*/