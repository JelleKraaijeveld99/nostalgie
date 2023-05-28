#include <iostream>
#include <opencv2/opencv.hpp>
#include <chrono>
#include <thread>
#include "analyse.h"
#include <filesystem>

using namespace cv;

int main() {
//    std::cout << "start main" << std::endl;
    Analyse analyse;
    std::cout << "analysis init" << std::endl;
//    analyse.analyseShapes("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/nostalgie/image_analysis/nostalgia_cpp/thuis.jpg");
    analyse.colorAnalyse("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/nostalgie/image_analysis/nostalgia_cpp/green.png");
    std::cout << "complete" << std::endl;

    waitKey(0);

/*//SECTION OF THE CODE FOR ANALYSING A PICTURE EVERY X SECONDS//
   //create an object for the camera
    VideoCapture cap(0);


    //check if the camera is available
    if (!cap.isOpened())
    {
        std::cerr << "Could not access the camera" << std::endl;
        return -1;
    }

    //make an empty variable for storing the frame from the camera
    Mat frame;
    //counter for counting when the frame has to be captured
    int count = 0;
    //variables for how max amount of pictures
    int pictureCount;
    int maxPictures = 10;


    while (true) {
        //storing a frame from the object cap in the frame variable
        cap >> frame;

        if (frame.empty()) { //checking if everything went right
            std::cerr << "Unable to capture frame" << std::endl;
            continue;
        }

        // Write the frame to a file every 10(?) seconds
        if (count % 5 == 0) {
            string filename = "image_test.png";
            cv::imwrite(filename, frame);

            // Get the path of the current working directory
            filesystem::path cwd = std::filesystem::current_path();
            cv::imwrite((cwd / filename).string(), frame);
            analyse.analyseShapes("/Users/jellekraaijeveld/Documents/HKU1/Jaar_2/CSD/nostalgie/image_analysis/nostalgia_cpp/cmake-build-debug/image_test.png");
            pictureCount++;

        }

        //stop the program after x amount of pictures
        if (pictureCount > maxPictures){
            break;
        }

        count++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

//    cap.release();
    waitKey(0);*/
    return 0;
}

