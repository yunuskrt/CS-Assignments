// Yunus Kerestecioglu

#include <iostream>
#include <string>
#include "TwoDShapes.h"
using namespace std;

double TwoDShape::volume()
{
    return 0;
}

rectangle::rectangle(string name, double w, double len)
{
    myName = name;
    width = w;
    length = len;
}

double rectangle::perimeter()
{
    return 2*(width+length);
}

double rectangle::area()
{
    return width*length;
}

string rectangle::getName()
{
    return myName;
}

