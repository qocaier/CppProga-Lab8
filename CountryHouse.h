#pragma once
#include "Property.h"

class CountryHouse : public Property
{
	double distanceFromCity;
public:
	CountryHouse(double w, double dfc) : distanceFromCity(dfc), Property(w) {};
};