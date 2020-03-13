#include <opencv2/opencv.hpp>
#include <opencv2/opencv_modules.hpp>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;

int main()
{
    Mat image;
    image = imread("donov.jpg", IMREAD_COLOR);

    if (!image.data)
    {
        std::cout << "could not open or find image" << std::endl;
        return -1;
    }

    namedWindow("Display window", WINDOW_AUTOSIZE);
    imshow("Display window", image);

    waitKey(0);

    return 0;
}