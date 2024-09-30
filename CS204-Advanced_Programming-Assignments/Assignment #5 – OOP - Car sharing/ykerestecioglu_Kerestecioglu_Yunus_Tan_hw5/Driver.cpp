// Yunus Tan Kerestecioglu

#include <iostream>
#include "Driver.h"
using namespace std;

//**************
// Constructor *
//**************
Driver::Driver(Car & car, int money)
 : sharedCar(car), budget(money)
{ }

//************************************************************
// increase the total distance. Also, reduce the fuel level. *
//************************************************************
void Driver::drive(int km)
{
	double change = km * 0.25;
	sharedCar.increaseKM(km);
	sharedCar.decreaseFuel(change);
}

//**************************************************
// increases the insurance fee,                    *
// decreases the budget according to accident type *
//**************************************************
void Driver::repairCar(string accident)
{
	if (accident == "SMALL")
	{
		budget -= 50;
		sharedCar.increaseFee(0.05);
		cout<< "50$ is reduced from the driver's budget because of the SMALL accident" << endl;
		cout << "Yearly insurance fee is increased to " << sharedCar.getInsFee() << " because of the SMALL accident" << endl;
	}
	else if (accident == "MEDIUM")
	{
		budget -= 150;
		sharedCar.increaseFee(0.1);
		cout<< "150$ is reduced from the driver's budget because of the MEDIUM accident" << endl;
		cout << "Yearly insurance fee is increased to " << sharedCar.getInsFee() << " because of the MEDIUM accident" << endl;
	}
	else // accident == "LARGE"
	{
		budget -= 300;
		sharedCar.increaseFee(0.2);
		cout<< "300$ is reduced from the driver's budget because of the LARGE accident" << endl;
		cout << "Yearly insurance fee is increased to " << sharedCar.getInsFee() << " because of the LARGE accident" << endl;
	}

}

//*******************************************************
// full the fuel of the car to its maximum level (300$) *
// the budget of the driver should decrease accordingly *
//*******************************************************
void Driver::fullFuel()
{
	double diff;
	sharedCar.fullFuel(diff);
	budget -= diff;
}

//***************************************
// display the current budget of driver *
//***************************************
void Driver::display() const
{
	cout << "Driver Budget: " << budget;
}