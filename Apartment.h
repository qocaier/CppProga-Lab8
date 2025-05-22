#pragma once
#include "Property.h"

class Apartment : public Property
{
	double square = 0;
public:
	Apartment() {};
	Apartment(unsigned int w, double s) : square(s), Property(w) {};

	double calcTax() override;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	string getData() override { return " -  вартира стоит " + to_string(worth) + ", площадь: " + to_string(square) + '\n'; };

	~Apartment() {};
};