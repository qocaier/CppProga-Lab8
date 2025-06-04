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

void CountryHouse::fromXml(const pugi::xml_node& xml)
{
    worth = stoul(xml.child_value("worth"));
    distanceFromCity = stoul(xml.child_value("distancefromcity"));
}

void CountryHouse::toXml(pugi::xml_node& xml)
{
    pugi::xml_node countryhouse_node = xml.append_child("countryhouse");

    pugi::xml_node tax_node = countryhouse_node.append_child("tax");
    tax_node.text().set(to_string(calcTax()).c_str());
}