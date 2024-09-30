// Yunus Kerestecioglu


#include <iostream>
#include <string>
using namespace std;

#ifndef shape_h
#define shape_h


class shape
{
    public:
        shape(){}
        virtual ~shape(){}
        virtual double perimeter() = 0; // pure virtual function
        virtual double area() = 0; // pure virtual function
        virtual double volume() = 0; // pure virtual function
        virtual string getName() = 0; // pure virtual function
};

#include "TwoDShapes.h"
#include "ThreeDShapes.h"

#endif /* Shape_h */

