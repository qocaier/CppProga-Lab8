#pragma once
#include "Apartment.h"
#include "CountryHouse.h"
#include "Car.h"

class PropertySimpleFactory
{
public:
	static Property* getProperty(std::string key);
};