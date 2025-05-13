#pragma once
#include <string>
#include "TaxRates.h"

using namespace std;
using namespace TAX_RATES;

class Property
{
protected:
	unsigned int worth;
public:
	Property(unsigned int w) : worth(w) {};

	virtual double calcTax() = 0;
	double calcIncomeTax() { return worth * 0.13; };

	unsigned int getWorth() { return worth; };
	void setWorth(unsigned int w) { worth = w; };
	virtual string getData() = 0;

	~Property() {};
};