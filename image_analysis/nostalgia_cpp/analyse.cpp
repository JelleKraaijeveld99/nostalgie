#include "analyse.h"


Analyse::Analyse() {
    //initialise the path variable

    //test
//    Mat srcImage = cv::imread(pathToImg); // Use full path!
//    imshow("[img]", srcImage);
}

Analyse::~Analyse() {

}

void Analyse::defineColor(uchar hue, uchar saturation, uchar value) {
    //variables
    uchar H = hue;
    uchar S = saturation;
    uchar V = value;

}

void Analyse::analyseColors(string path) {
    //variables for all the colors in the picture:
    int black;
    int gray;
    int white;
    int red;
    int orange;
    int yellow;
    int green;
    int blue;
    int purple;
    int brown;
    int pink;

    pathToImg = path;
    srcImg = imread(pathToImg);
    imshow("[test]",srcImg);


    //variable for storing the hsv image so we can extract the hue value from the saturation and value
    Mat HSV;
    cvtColor(srcImg, HSV, COLOR_BGR2HSV) ;
    imshow("HSV",HSV);
    std::cout << "this is the type: " << HSV.type() << std::endl;

    //make empty vector for storing hue, saturation and value per pixel
    vector<Mat> channels;
    split(HSV, channels);
    //extract the hue value
    Mat hue = channels[0];
    Mat saturation = channels[1];
    Mat value = channels[2];
    imshow("saturation",saturation);
    imshow("value",value);
    imshow("hue®",hue);
    std::cout << "this is the hue type: " << hue.type() << std::endl;


    for(int y = 0; y <hue.rows; y++) {
        for (int x = 0; x < hue.cols; x++) {
            channels[1].at<uchar>(y, x) = 255;
        }
    }
    Mat mergedChannels;
    merge(channels, mergedChannels);
    Mat RGBmergedChannels;
    cvtColor(mergedChannels, RGBmergedChannels, COLOR_HSV2BGR) ;
    imshow("mergedchannels",RGBmergedChannels);


            //iterate over each pixel by first making a for loop going through the height of the picture and in this for loop iterate over the width
    for(int y = 0; y < 1; y++){
        for(int x = 0; x <20; x++){
//            uchar hueValue = hue.at<uchar>(y,x);
            uchar saturationValue = saturation.at<uchar>(y,x);
            uchar valueValue = value.at<uchar>(y,x);

//              std::cout << "Pixel hue at (" << x << ", " << y << "): " << static_cast<int>(hueValue) << std::endl;
              std::cout << "Pixel saturation at (" << x << ", " << y << "): " << static_cast<int>(saturationValue) << std::endl;
              std::cout << "Pixel value at (" << x << ", " << y << "): " << static_cast<int>(valueValue) << std::endl;
        }
    }


}/**/

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
    int fake_timestamp=0;;

    target = lo_address_new("localhost","7777");
    std::cout << "HOPPA " << std::endl;

    lo_send(target,"/red","sf","red",perRed);
    lo_send(target,"/blue","sf","blue",perBlue);
    lo_send(target,"/green","sf","green",perGreen);
    lo_send(target,"/purple","sf","purple",perPurple);
    lo_send(target,"/pink","sf","pink",perPink);
    lo_send(target,"/orange","sf","orange",perOrange);
    lo_send(target,"/yellow","sf","yellow",perYellow);
    lo_send(target,"/cyan","sf","cyan",perCyan);

//    while(1)
//    {
//        cin >> symbol;
//        if(symbol == "quit" || symbol == "q") break;
//        else if(symbol == "send" || symbol == "s") {
//            lo_send(target,"/sound","siii","pitch",1,1,42);
//            lo_send(target,"/tactile","ii",1,42);
//        }
//
//        fake_timestamp++;
//    }
}

void Analyse::analyseShapes(string path) {
//    pathToImg = path;
//    RNG rng(12345);
//    //declaring the srcImg variable
//    srcImg = imread(pathToImg);
//    //convert the source image to gray with the destination: grayImg
//    cvtColor(srcImg,grayImg, COLOR_BGR2GRAY);
//    //convert the gray image to an image with upscaling to values that make white background
//    //apply a blur filter to the gray image
//    blur(grayImg, grayImg, Size(2,2));
//    imshow("[img]", grayImg);
//
//    //adaptive thresholding so the thresholding is more accurate and doest filter out whole pieces of the image
//    adaptiveThreshold(grayImg, threshImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 17, 40);
//    imshow("[img]", threshImg);
//
//    // apply morphology operations to remove noise
//    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
//    morphologyEx(threshImg, threshImg, MORPH_OPEN, kernel, Point(-1,-1), 2);
//    imshow("[threshhhimg]", threshImg);
//
//    imshow("[img]", threshImg);
//
//    vector<vector<Point> > contours;
//    vector<Vec4i> hierarchy;
//    findContours( threshImg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );
//
////    Mat drawing = Mat::zeros( threshImg.size(), CV_8UC3 );
//
//    for (int i = 0; i < contours.size(); i++)
//    {
//        if (i == 0)
//            continue;
//        if (i >= contours.size())
//            break;
//        double epsilon = 0.01 * arcLength(contours[i], true);
//        std::vector<Point> approx;
//        approxPolyDP(contours[i], approx, epsilon, true);
//        drawContours(srcImg,contours,0,(0,0,0),4);
//
//        //parameters for writing the shape in the picture
//        Rect boundRect = boundingRect(approx);
//        int x = boundRect.x;
//        int y = boundRect.y;
//        int w = boundRect.width;
//        int h = boundRect.height;
//        int x_mid = int(x + w/2);
//        int y_mid = int(y + h/2);
//        auto font = FONT_HERSHEY_COMPLEX_SMALL;
//
//
//        if (approx.size() == 3){
//            putText(srcImg,"triangle", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
//            notCircleAmount++;
//        }
//
//        else if (approx.size() == 4){
//            putText(srcImg,"square", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
//            notCircleAmount++;
//        }
//
//        else if (approx.size() == 5){
//            putText(srcImg,"pentagon", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
//            notCircleAmount++;
//        }
//
//        else if (approx.size() == 6){
//            putText(srcImg,"hexagon", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
//            notCircleAmount++;
//        }
//
//        else if(approx.size() > 15) {
//            putText(srcImg,"circle", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
//            circleAmount++;
//        }
//
//
//    }
//    std::cout << "CIRCLE AMOUNT: " << circleAmount<< std::endl;;
//    std::cout << "NOT CIRCLE AMOUNT: " << notCircleAmount << std::endl;
//    imshow( "Contours", srcImg );

}


int Analyse::getColors() {

}

int Analyse::getShapes() {

}