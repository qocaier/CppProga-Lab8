#pragma once
#include <string>
#include <vector>
#include "Property.h"

class Owner
{
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(string fn, string nn) : fullname(fn), inn(nn) {};

	void addProperty(Property* property);
	void delProperty(unsigned int n);
	double calcSumTax();

	~Owner() {};
};