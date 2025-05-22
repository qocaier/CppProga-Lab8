#pragma once
#include <vector>
#include "Property.h"
#include "PropertySimpleFactory.h"

class Owner : Ijsonio
{
	string fullname;
	string inn;
	vector<Property*> properties;
public:
	Owner(string fn, string nn);

	void addProperty(Property* property);
	void delProperty(unsigned int n);
	double calcSumTax();

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;

	string getData() { return fullname + ", »ÕÕ: " + inn + '\n'; };
	vector<Property*> getProperties() { return properties; };
	// string getProperties() { string s = ""; for (Property* prop : properties) s += typeof(*prop); };

	~Owner() {};
};