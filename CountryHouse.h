#pragma once
#include "Property.h"

class CountryHouse : public Property
{
	unsigned int distanceFromCity;
public:
	CountryHouse(unsigned int w, unsigned int dfc) : distanceFromCity(dfc), Property(w) {};

	double calcTax() override;

	string getData() override { return " - ����� ����� " + to_string(worth) + ", ����������� �� ������: " + to_string(distanceFromCity) + '\n'; };

	~CountryHouse() {};
};