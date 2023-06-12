#include "analyse.h"


Analyse::Analyse() {

}

Analyse::~Analyse() {

}


void Analyse::colorAnalyse(std::string path) {

    //initialisation
    pathToImg = path;
    srcImg = imread(pathToImg);
    imshow("[source]",srcImg);

    //convert RGB to HSV values
    Mat hsv;
    cvtColor(srcImg, hsv, cv::COLOR_BGR2HSV );

    //split the HSV values in three channels
    Mat hsvChannels[3];
    split(hsv, hsvChannels);

    //display the three different channels H S V as grayscale image
    // ==========  show result ==========
    imshow("hue", hsvChannels[0]);
    imshow("saturation", hsvChannels[1]);
    imshow("value", hsvChannels[2]);
    imshow("generated", srcImg);

// apply mask to remove 'too white colors'
    // should result in an image without the polygon
    // create a mask image
    Mat saturationMask;
    // E.G. --> with mask 20 or 10, different results
    int thresholdValue = 20;
    threshold(hsvChannels[1], saturationMask,thresholdValue, 255, THRESH_BINARY_INV );
    saturationMask = 255 - saturationMask;
    threshold(hsvChannels[1], saturationMask,thresholdValue, 255, THRESH_BINARY );
    imshow("saturationMask", saturationMask);

    // apply mask to filter out the color white
    Mat maskedImg;
    srcImg.copyTo(maskedImg, saturationMask);
    imshow("generated & masked", maskedImg);

    Mat hsvMaskedImg;
    cvtColor(maskedImg, hsvMaskedImg, cv::COLOR_BGR2HSV );

    Mat maskedChannels[3];
    split(hsvMaskedImg,maskedChannels);
    imshow("hue masked", maskedChannels[0]);



    for(int y = 0; y <maskedChannels[0].rows; y++) {
        for (int x = 0; x < maskedChannels[0].cols; x++) {
            uchar hueValue = maskedChannels[0].at<uchar>(y, x);
//            std::cout << "Pixel hue at (" << x << ", " << y << "): " << static_cast<int>(hueValue) << std::endl;
            pixelAmount++;

            //check how many pixels are orange
            if(hueValue >= 11 && hueValue <= 25){
                orange++;
            }

            //check how many pixels are yellow
            if(hueValue >= 26 && hueValue <= 34){
                yellow++;
            }

            //check how many pixels are green
            if(hueValue >= 35 && hueValue <= 80){
                green++;
            }

            //check how many pixels are cyan
            if(hueValue >= 81 && hueValue <= 89){
                cyan++;
            }

            //check how many pixels are blue
            if(hueValue >= 90 && hueValue <= 130){
                blue++;
            }

            //check how many pixels are purple
            if(hueValue >= 131 && hueValue <= 141){
                purple++;
            }

            //check how many pixels are pink
            if(hueValue >= 142 && hueValue <= 163){
                pink++;
            }

            //check how many pixels are red
            if((hueValue > 0 && hueValue <= 10)||(hueValue >= 164 && hueValue <= 180)){
                red++;
            }



//
        }
    }
    std::cout << "amount of pixels: " << pixelAmount << std::endl;
    std::cout << "amount of green pixels: " << green << std::endl;
    std::cout << "amount of red pixels: " << red << std::endl;
    std::cout << "amount of blue pixels: " << blue << std::endl;
    std::cout << "amount of cyan pixels: " << cyan << std::endl;
    std::cout << "amount of yellow pixels: " << yellow << std::endl;
    std::cout << "amount of orange pixels: " << orange << std::endl;
    std::cout << "amount of pink pixels: " << pink << std::endl;
    std::cout << "amount of purple pixels: " << purple << std::endl;

    colorPercentage();

}

void Analyse::colorPercentage() {

    int totalColoredPixels = red + blue + green + purple + pink + orange + yellow + cyan;

    perRed = ((float) red/totalColoredPixels)*100.0;
    perBlue = ((float) blue/totalColoredPixels)*100;
    perGreen = ((float) green/totalColoredPixels)*100;
    perPurple = ((float) purple/totalColoredPixels)*100;
    perPink = ((float) pink/totalColoredPixels)*100;
    perOrange = ((float) orange/totalColoredPixels)*100;
    perYellow = ((float) yellow/totalColoredPixels)*100;
    perCyan = ((float) cyan/totalColoredPixels)*100;

    std::cout << "amount of pixels: " << pixelAmount << std::endl;
    std::cout << "% of green pixels: " << perGreen << std::endl;
    std::cout << "% of red pixels: " << perRed << std::endl;
    std::cout << "% of blue pixels: " << perBlue << std::endl;
    std::cout << "% of cyan pixels: " << perPurple << std::endl;
    std::cout << "% of yellow pixels: " << perPink << std::endl;
    std::cout << "% of orange pixels: " << perOrange << std::endl;
    std::cout << "% of pink pixels: " << perYellow << std::endl;
    std::cout << "% of purple pixels: " << perCyan << std::endl;

}

void Analyse::sendPercentageOSC() {
    lo_address target;
    string symbol;

    //set adress for OSC
    target = lo_address_new("localhost","7777");

    lo_send(target,"/red","sf","red",perRed);
    lo_send(target,"/blue","sf","blue",perBlue);
    lo_send(target,"/green","sf","green",perGreen);
    lo_send(target,"/purple","sf","purple",perPurple);
    lo_send(target,"/pink","sf","pink",perPink);
    lo_send(target,"/orange","sf","orange",perOrange);
    lo_send(target,"/yellow","sf","yellow",perYellow);
    lo_send(target,"/cyan","sf","cyan",perCyan);

}

