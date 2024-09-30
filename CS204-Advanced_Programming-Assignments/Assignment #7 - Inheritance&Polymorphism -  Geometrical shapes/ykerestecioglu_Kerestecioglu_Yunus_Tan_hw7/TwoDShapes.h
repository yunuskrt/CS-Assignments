// Yunus Kerestecioglu

#ifndef TwoDShapes_h
#define TwoDShapes_h

#include <string>
#include "Shape.h"


using namespace std;

class TwoDShape: public shape
{
    public:
        TwoDShape(){}
        virtual ~TwoDShape(){}
        virtual double volume(); // virtual function
        virtual double perimeter() = 0; // pure virtual function
        virtual double area() = 0; // pure virtual function
        virtual string getName() = 0; // pure virtual function
};


class rectangle: public TwoDShape
{
    public:
        rectangle(string name, double w, double len);
        virtual ~rectangle(){}
        virtual double perimeter(); 
        virtual double area(); 
        virtual string getName();
    private:
        double width;
        double length;
        string myName;
};

#endif /* TwoDShapes_h */
