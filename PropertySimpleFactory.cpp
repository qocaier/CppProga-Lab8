#include "PropertySimpleFactory.h"

Property* PropertySimpleFactory::getProperty(std::string key)
{
    if (key == "apartment") return new Apartment();
    if (key == "car") return new Car();
    if (key == "countryhouse") return new CountryHouse();
    throw invalid_argument("invalid argument");
}