#pragma once
#include "Property.h"

class Apartment : public Property
{
	double square;
public:
	Apartment(double w, double s) : square(s), Property(w) {};
};