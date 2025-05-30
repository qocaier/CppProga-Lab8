#pragma once
#include "Property.h"

class CountryHouse : public Property
{
	unsigned int distanceFromCity = 0;
public:
	CountryHouse() {};
	CountryHouse(unsigned int w, unsigned int dfc) : Property(w), distanceFromCity(dfc) {};

	double calcTax() override;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	string getData() override { return " - Вилла стоит " + to_string(worth) + ", удаленность от города: " + to_string(distanceFromCity) + '\n'; };

	~CountryHouse() {};
};