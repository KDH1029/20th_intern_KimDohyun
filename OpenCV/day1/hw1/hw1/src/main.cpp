#include "main.h"

int main(int argc, char **argv)
{
    cv::Mat img = cv::imread("balloon.png");
    cv::Mat hsv, blurred;
    cv::cvtColor(img, hsv, cv::COLOR_BGR2HSV);
    cv::GaussianBlur(img, blurred, cv::Size(5, 5), 0);
    cv::cvtColor(blurred, blurred, cv::COLOR_BGR2HSV);

    cv::imshow("Original", img);
    cv::imshow("Red", red(hsv));
    cv::imshow("Red_Blurred", red(blurred));
    cv::imshow("Green", green(hsv));
    cv::imshow("Green_Blurred", green(blurred));
    cv::imshow("Blue", blue(hsv));
    cv::imshow("Blue_Blurred", blue(blurred));
    cv::waitKey(0);

    return 0;
}
