#pragma once
#include "Apartment.h"
#include "CountryHouse.h"
#include "Car.h"

enum property_type { APARTMENT, CAR, COUNTRYHOUSE };
typedef map<property_type, Property*> propertyMap;

class Factory
{
	Factory();
public:
	static Property* create(property_type type);
};