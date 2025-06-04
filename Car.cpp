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

void Car::fromXml(const pugi::xml_node& xml)
{
    worth = stoul(xml.child_value("worth"));
    horsepower = stod(xml.child_value("horsepower"));
}

void Car::toXml(pugi::xml_node& xml)
{
    pugi::xml_node car_node = xml.append_child("car");

    pugi::xml_node tax_node = car_node.append_child("tax");
    tax_node.text().set(to_string(calcTax()).c_str());
}