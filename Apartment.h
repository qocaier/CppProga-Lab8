#pragma once
#include "Property.h"

class Apartment : public Property
{
	double square;
public:
	Apartment(unsigned int w, double s) : square(s), Property(w) {};

	double calcTax() override;

	~Apartment() {};
};