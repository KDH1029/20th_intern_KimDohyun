#include <opencv2/opencv.hpp>

cv::Mat red(cv::Mat original)
{
    cv::Mat mask1, mask2, mask;
    cv::inRange(original, cv::Scalar(0, 120, 70), cv::Scalar(10, 255, 255), mask1);
    cv::inRange(original, cv::Scalar(170, 120, 70), cv::Scalar(180, 255, 255), mask2);
    cv::bitwise_or(mask1, mask2, mask);
    return mask;
}

cv::Mat green(cv::Mat original)
{
    cv::Mat mask;
    cv::inRange(original, cv::Scalar(35, 100, 100), cv::Scalar(85, 255, 255), mask);
    return mask;
}

cv::Mat blue(cv::Mat original)
{
    cv::Mat mask;
    cv::inRange(original, cv::Scalar(95, 100, 100), cv::Scalar(130, 255, 255), mask);
    return mask;
}