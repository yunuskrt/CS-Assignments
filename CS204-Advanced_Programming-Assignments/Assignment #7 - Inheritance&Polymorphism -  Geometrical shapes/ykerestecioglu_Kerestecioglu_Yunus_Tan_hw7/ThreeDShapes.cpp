// Yunus Kerestecioglu

#include <iostream>
#include <string>
#include "ThreeDShapes.h"
using namespace std;


double ThreeDShape::perimeter()
{
    return 0;
}


box::box(string name, double w, double len, double h)
{
    myName = name;
    width = w;
    length = len;
    height = h;
}

double box::area()
{
    return 2*(width*length+width*height+length*height);
}

double box::volume()
{
    return width*length*height;
}

string box::getName()
{
    return myName;
}
