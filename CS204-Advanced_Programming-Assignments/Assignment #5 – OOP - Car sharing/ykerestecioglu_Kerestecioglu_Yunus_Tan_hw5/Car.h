// Yunus Tan Kerestecioglu

#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car
{
private:
	double maxFuel;
	double fuel;
	double insurance_fee;
	int km_passed;
public:
	// Constructor.
	Car(double f, double ins, int km);

	// Member functions.
	void display() const;
	void increaseKM(int change);
	void decreaseFuel(double change);
	void increaseFee(double perc);
	void fullFuel(double & diff);
	double getInsFee();
};
#endif