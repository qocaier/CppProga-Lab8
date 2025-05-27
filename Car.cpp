#include "Car.h"

double Car::calcTax()
{
    if (horsepower < LOW_HORSEPOWER) return worth * CAR_TAX;
    if (horsepower > HIGH_HORSEPOWER) return worth * CAR_LUXURY_TAX;
    return worth * CAR_TRUCK_TAX;
}

void Car::fromJson(nlohmann::json json)
{
    worth = json["worth"].get<int>();
    horsepower = json["horsepower"].get<double>();
}

nlohmann::json Car::toJson()
{
    nlohmann::json json;
    json["Car"]["tax"] = calcTax();
    return json;
}