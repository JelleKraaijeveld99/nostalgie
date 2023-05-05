#include "analyse.h"

Analyse::Analyse(string path) {
    //initialise the path variable
    pathToImg = path;

    //test
//    Mat srcImage = cv::imread(pathToImg); // Use full path!
//    imshow("[img]", srcImage);
}

Analyse::~Analyse() {

}

void Analyse::analyseColors() {

}

void Analyse::analyseShapes() {
    RNG rng(12345);
    //declaring the srcImg variable
    srcImg = imread(pathToImg);
    //convert the source image to gray with the destination: grayImg
    cvtColor(srcImg,grayImg, COLOR_BGR2GRAY);
    //convert the gray image to an image with upscaling to values that make white background
    threshold(grayImg,threshImg,140,255,THRESH_BINARY);

    vector<vector<Point> > contours;
    vector<Vec4i> hierarchy;
    findContours( threshImg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE );

    Mat drawing = Mat::zeros( threshImg.size(), CV_8UC3 );
    for( size_t i = 0; i< contours.size(); i++ )
    {
        Scalar color = Scalar( rng.uniform(0, 256), rng.uniform(0,256), rng.uniform(0,256) );
        drawContours( drawing, contours, (int)i, color, 2, LINE_8, hierarchy, 0 );
    }
    imshow( "Contours", drawing );
    imshow("[img]", grayImg);

}

int Analyse::getColors() {

}

int Analyse::getShapes() {

}