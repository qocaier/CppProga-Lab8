#include "CountryHouse.h"

double CountryHouse::calcTax()
{
    if (distanceFromCity <= LIMIT_DISTANCE_FROM_CITY) return worth * Apartment_TAX;
    return worth * COUNTRY_HOUSE_TAX;
}