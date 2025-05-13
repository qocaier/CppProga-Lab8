#pragma once
#include "Property.h"

class Car : public Property
{
	double horsepower;
public: 
	Car(unsigned int w, double hp) : horsepower(hp), Property(w) {};

	double calcTax() override;

	~Car() {};
};