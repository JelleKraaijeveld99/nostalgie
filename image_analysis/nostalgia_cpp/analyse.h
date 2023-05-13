#ifndef _ANA_H_
#define _ANA_H_
#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <utility>


using namespace std;
using namespace cv;

class Analyse {
public:
//constructor and deconstructor
    Analyse(string path);
    ~Analyse();

//setters and getters
    int getShapes();
    int getColors();

//functions for retrieving information
    void analyseShapes();
    void analyseColors();

//variables to store the results of the analysis
    char *colorStringArr;
    char *shapeStringArr;
    int *colorIntArr;
    int *shapeIntArr;

    //variable for the path
    string pathToImg;

    //variable for the source and converted gray image and converted threshold image
    Mat srcImg;
    Mat grayImg;
    Mat threshImg;

    int circleAmount;
    int notCircleAmount;

//TODO: PERCENTAGE OF COLORS
};

#endif