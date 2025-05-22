#include "PropertySimpleFactory.h"

Property* PropertySimpleFactory::getProperty(std::string key)
{
    if (key == "Apartment") {
        Apartment a;
        return &a;
    }
    if (key == "Car") {
        Car a;
        return &a;
    }
    if (key == "CountryHouse") {
        CountryHouse a;
        return &a;
    }
    throw invalid_argument("invalid argument");
}
