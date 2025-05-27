#include "Factory.h"

Property* Factory::create(property_type type)
{
	propertyMap m =
	{
		{APARTMENT, new Apartment()},
		{CAR, new Car()},
		{COUNTRYHOUSE, new CountryHouse()}
	};
	return m[type];
}