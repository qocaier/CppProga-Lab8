#include "CountryHouse.h"

double CountryHouse::calcTax()
{
    if (distanceFromCity <= LIMIT_DISTANCE_FROM_CITY) return worth * Apartment_TAX;
    return worth * COUNTRY_HOUSE_TAX;
}

void CountryHouse::fromJson(nlohmann::json json)
{
    worth = json["worth"].get<int>();
    distanceFromCity = json["distanceFromCity"].get<unsigned int>();
}

nlohmann::json CountryHouse::toJson()
{
    nlohmann::json json;
    json["CountryHouse"]["tax"] = calcTax();
    return json;
}