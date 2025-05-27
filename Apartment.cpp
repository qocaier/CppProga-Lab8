#include "Apartment.h"

double Apartment::calcTax()
{
    if (square <= LIMIT_Apartment_SQUARE) return worth * Apartment_TAX;
    return worth * Apartment_LUXURY_TAX;
}

void Apartment::fromJson(nlohmann::json json)
{
    worth = json["worth"].get<int>();
    square = json["square"].get<double>();
}

nlohmann::json Apartment::toJson()
{
    nlohmann::json json;
    json["Apartment"]["tax"] = calcTax();
    return json;
}