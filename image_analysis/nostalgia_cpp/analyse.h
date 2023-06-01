#ifndef _ANA_H_
#define _ANA_H_
#pragma once

#include <opencv2/opencv.hpp>
#include <string>
#include <utility>
#include "osc.h"
#include <lo/lo.h>


using namespace std;
using namespace cv;

class Analyse {
public:
//constructor and deconstructor
    Analyse();
    ~Analyse();

//setters and getters
    int getShapes();
    int getColors();

//functions for retrieving information
    void analyseShapes(string path);
    void analyseColors(string path);
    //new color analyse function
    void colorAnalyse(string path);
    void defineColor(uchar hue, uchar saturation, uchar value);
    void colorPercentage();
    void sendPercentageOSC();

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


    int pixelAmount = 0;

    //all colors to be analysed
    int green = 0;
    int red = 0;
    int blue = 0;
    int cyan = 0;
    int orange = 0;
    int yellow = 0;
    int purple = 0;
    int pink = 0;

    //the percentages of the colors
    float perRed;
    float perBlue;
    float perGreen;
    float perPurple;
    float perPink;
    float perOrange;
    float perYellow;
    float perCyan;


//TODO: PERCENTAGE OF COLORS
};

#endif