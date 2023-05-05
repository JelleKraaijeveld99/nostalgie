#ifndef _ANA_H_
#define _ANA_H_
#pragma once

#include <string>
using namespace std

class Analyse {
public:
//constructor and deconstructor
    Analyse();
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
};

#endif