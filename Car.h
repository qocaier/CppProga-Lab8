#pragma once
#include "Property.h"

class Car : public Property
{
	double horsepower;
public: 
	Car(double w, double hp) : horsepower(hp), Property(w) {};
};