#pragma once
#include <vector>
#include "Property.h"
#include "PropertySimpleFactory.h"
#include "Factory.h"

class Owner : public Ijsonio, public Ixmlio
{
	string fullname = "";
	string inn = "";
	vector<Property*> properties = {};
public:
	Owner() {};
	Owner(string fn, string nn);

	void addProperty(Property* property);
	void delProperty(unsigned int n);
	double calcSumTax();

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;
	void fromXml(const pugi::xml_node& xml) override;
	void toXml(pugi::xml_node& xml) override;

	string getData() { return fullname + ", »ÕÕ: " + inn + '\n'; };
	vector<Property*> getProperties() { return properties; };
	// string getProperties() { string s = ""; for (Property* prop : properties) s += typeof(*prop); };

	~Owner() {};
};