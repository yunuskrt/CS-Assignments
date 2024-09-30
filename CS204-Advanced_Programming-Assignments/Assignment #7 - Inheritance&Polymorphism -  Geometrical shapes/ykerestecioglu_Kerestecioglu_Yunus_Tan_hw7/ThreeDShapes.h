// Yunus Kerestecioglu

#ifndef ThreeDShapes_h
#define ThreeDShapes_h

#include <string>
#include "Shape.h"
using namespace std;



class ThreeDShape: public shape
{
    public:
        ThreeDShape(){}
        virtual ~ThreeDShape(){}
        virtual double volume() = 0; // pure virtual function
        virtual double perimeter(); // virtual function
        virtual double area() = 0; // pure virtual function
        virtual string getName() = 0; // pure virtual function
};


class box: public ThreeDShape
{
    public:
        box(string name, double w, double len, double h);
        virtual double area(); 
        virtual double volume(); 
        virtual string getName();
    private:
        string myName;
        double width;
        double length;
        double height;
};

#endif /* ThreeDShapes_h */
