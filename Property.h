#pragma once

class Property
{
protected:
	double worth;
public:
	Property(double w) : worth(w) {};

	virtual double calcTax();
	double calcLuxuryTax();
};