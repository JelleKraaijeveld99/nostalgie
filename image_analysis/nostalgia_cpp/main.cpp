#include <iostream>
#include <opencv2/opencv.hpp>
#include "analyse.h"

using namespace cv;

int main() {
    cv::Mat srcImage = cv::imread("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/nostalgie/image_analysis/nostalgia_cpp/thuis.jpg"); // Use full path!
    cv::imshow("[img]", srcImage);
    cv::waitKey(0);
    return 0;
}
