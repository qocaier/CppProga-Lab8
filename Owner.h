#pragma once
#include <vector>
#include "Property.h"

class Owner
{
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(string fn, string nn);

	void addProperty(Property* property);
	void delProperty(unsigned int n);
	double calcSumTax();

	string getData() { return fullname + ", »ÕÕ: " + inn + '\n'; };
	vector<Property*> getProperties() { return properties; };
	// string getProperties() { string s = ""; for (Property* prop : properties) s += typeof(*prop); };

	~Owner() {};
};