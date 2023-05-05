#include "analyse.h"

Analyse::Analyse(string path) {
    //initialise the path variable
    pathToImg = path;
    //
    Mat srcImage = cv::imread(path); // Use full path!
    imshow("[img]", srcImage);
}

Analyse::~Analyse() {

}

void Analyse::analyseColors() {

}

void Analyse::analyseShapes() {

}

int Analyse::getColors() {

}

int Analyse::getShapes() {

}