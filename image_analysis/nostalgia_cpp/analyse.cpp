#include "analyse.h"


Analyse::Analyse() {
    //initialise the path variable

    //test
//    Mat srcImage = cv::imread(pathToImg); // Use full path!
//    imshow("[img]", srcImage);
}

Analyse::~Analyse() {

}

void Analyse::analyseColors() {

}

void Analyse::analyseShapes(string path) {
    pathToImg = path;
    RNG rng(12345);
    //declaring the srcImg variable
    srcImg = imread(pathToImg);
    //convert the source image to gray with the destination: grayImg
    cvtColor(srcImg,grayImg, COLOR_BGR2GRAY);
    //convert the gray image to an image with upscaling to values that make white background
    //apply a blur filter to the gray image
    blur(grayImg, grayImg, Size(2,2));
    imshow("[img]", grayImg);

    //adaptive thresholding so the thresholding is more accurate and doest filter out whole pieces of the image
    adaptiveThreshold(grayImg, threshImg, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 17, 40);
    imshow("[img]", threshImg);

    // apply morphology operations to remove noise
    Mat kernel = getStructuringElement(MORPH_ELLIPSE, Size(5, 5));
    morphologyEx(threshImg, threshImg, MORPH_OPEN, kernel, Point(-1,-1), 2);
    imshow("[threshhhimg]", threshImg);

    imshow("[img]", threshImg);

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( threshImg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );

//    Mat drawing = Mat::zeros( threshImg.size(), CV_8UC3 );

    for (int i = 0; i < contours.size(); i++)
    {
        if (i == 0)
            continue;
        if (i >= contours.size())
            break;
        double epsilon = 0.01 * arcLength(contours[i], true);
        std::vector<Point> approx;
        approxPolyDP(contours[i], approx, epsilon, true);
        drawContours(srcImg,contours,0,(0,0,0),4);
        Rect boundRect = boundingRect(approx);
        int x = boundRect.x;
        int y = boundRect.y;
        int w = boundRect.width;
        int h = boundRect.height;
        int x_mid = int(x + w/2);
        int y_mid = int(y + h/2);
        auto font = FONT_HERSHEY_COMPLEX_SMALL;


        if (approx.size() == 3){
            putText(srcImg,"triangle", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
            notCircleAmount++;
        }

        else if (approx.size() == 4){
            putText(srcImg,"square", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
            notCircleAmount++;
        }

        else if (approx.size() == 5){
            putText(srcImg,"pentagon", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
            notCircleAmount++;
        }

        else if (approx.size() == 6){
            putText(srcImg,"hexagon", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
            notCircleAmount++;
        }

        else if(approx.size() > 15) {
            putText(srcImg,"circle", Point(x_mid,y_mid),font,1,Scalar(0,255,0),2,false);
            circleAmount++;
        }


    }
    std::cout << "CIRCLE AMOUNT: " << circleAmount<< std::endl;;
    std::cout << "NOT CIRCLE AMOUNT: " << notCircleAmount << std::endl;
    imshow( "Contours", srcImg );

}


int Analyse::getColors() {

}

int Analyse::getShapes() {

}