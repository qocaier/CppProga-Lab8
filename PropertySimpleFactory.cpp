#include "PropertySimpleFactory.h"

Property* PropertySimpleFactory::getProperty(std::string key)
{
    if (key == "Apartment") return new Apartment();
    if (key == "Car") return new Car();
    if (key == "CountryHouse") return new CountryHouse();
    throw invalid_argument("invalid argument");
}