// Yunus Tan Kerestecioglu

#ifndef DRIVER_H
#define DRIVER_H
#include <string>
#include "Car.h"
using namespace std;

class Driver
{
private:
	double budget; // budget of driver
	Car & sharedCar;  // shared object from Car class
public:
	// Constructor.
	Driver(Car & car, int money);

	// Member functions.
	void drive (int);
	void repairCar(string);
	void display() const;
	void fullFuel();
};
#endif