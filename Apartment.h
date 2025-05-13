#pragma once
#include "Property.h"

class Apartment : public Property
{
	double square;
public:
	Apartment(unsigned int w, double s) : square(s), Property(w) {};

	double calcTax() override;

	string getData() override { return " - �������� ����� " + to_string(worth) + ", �������: " + to_string(square) + '\n'; };

	~Apartment() {};
};