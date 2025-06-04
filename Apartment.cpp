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

void Apartment::fromXml(const pugi::xml_node& xml)
{
    worth = stoul(xml.child_value("worth"));
    square = stod(xml.child_value("square"));
}

void Apartment::toXml(pugi::xml_node& xml)
{
    pugi::xml_node apartment_node = xml.append_child("apartment");

    pugi::xml_node tax_node = apartment_node.append_child("tax");
    tax_node.text().set(to_string(calcTax()).c_str());
}