#pragma once
#include "Property.h"

class Apartment : public Property
{
	double square;
public:
	Apartment(unsigned int w, double s) : square(s), Property(w) {};

	double calcTax() override;

	string getData() override { return " -  вартира стоит " + to_string(worth) + ", площадь: " + to_string(square) + '\n'; };

	~Apartment() {};
};