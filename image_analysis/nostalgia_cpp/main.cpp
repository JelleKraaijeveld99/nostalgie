#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat srcImage = cv::imread("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/nostalgie/image_analysis/cpp_nostalgie/thuis.jpg"); // Use full path!
    cv::imshow("[img]", srcImage);
    cv::waitKey(0);
    return 0;
}
