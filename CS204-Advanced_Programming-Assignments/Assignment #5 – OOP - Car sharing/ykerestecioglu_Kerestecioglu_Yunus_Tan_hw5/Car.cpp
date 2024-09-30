// Yunus Tan Kerestecioglu

#include <iostream>
#include "Car.h"
using namespace std;

//**************
// Constructor *
//**************
Car::Car(double f, double ins, int km)
 : maxFuel(f), fuel(f), insurance_fee(ins), km_passed(km)
{ }

//****************************************
// increases the kilometer passed by car *
//****************************************
void Car::increaseKM(int change)
{
	km_passed += change;
}

//********************************
// decreases the fuel of the car *
//********************************
void Car::decreaseFuel(double change)
{
	fuel -= change;
}

//*****************************************
// increases the insurance fee of the car *
//*****************************************
void Car::increaseFee(double perc)
{
	insurance_fee += (insurance_fee * perc);
}

//***************************************************
// Make fuel full (the maximum level),              *
// returns diff between full level and current fuel * 
//***************************************************
void Car::fullFuel(double & diff)
{
	diff = (maxFuel - fuel);
	fuel = maxFuel;
	cout << "Fuel is full" << endl << endl;
}

//***************************************************************
// display the fuel level, insurance fee and the total distance *
//***************************************************************
void Car::display() const
{
	cout << "Fuel Level: " << fuel << endl
		<< "Insurance Fee: " << insurance_fee << endl
		<< "Total distance that the car has travelled: " << km_passed << endl << endl;

}

//************************
// returns insurance fee *
//************************
double Car::getInsFee()
{
	return insurance_fee;
}