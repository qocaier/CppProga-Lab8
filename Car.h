#pragma once
#include "Property.h"

class Car : public Property
{
	double horsepower = 0;
public: 
	Car() {};
	Car(unsigned int w, double hp) : horsepower(hp), Property(w) {};

	double calcTax() override;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	string getData() override { return " - Тачка стоит " + to_string(worth) + ", мощность: " + to_string(horsepower) + '\n'; };

	~Car() {};
};