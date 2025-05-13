#pragma once

class Property
{
	double worth;
public:
	Property(double w) : worth(w) {};

	virtual double calcTax();
	double calcLuxuryTax();
};