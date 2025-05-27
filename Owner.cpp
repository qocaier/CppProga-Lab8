#include "Owner.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Owner::Owner(string fn, string nn) : fullname(fn), inn(nn) {
	if (nn.length() != 12) throw invalid_argument("invalid argument");
	string nums = "0123456789";
	for (char c : nn) if (nums.find(c) == -1) throw invalid_argument("invalid argument");
}

void Owner::addProperty(Property* property)
{
	properties.push_back(property);
}

void Owner::delProperty(unsigned int n)
{
	if (n < 0 || n >= properties.size()) throw invalid_argument("invalid argument");
	properties.erase(properties.begin() + n);
}

double Owner::calcSumTax()
{
	double s = 0;
	for (int i = 0; i < properties.size(); i++) s += properties[i]->calcTax();
	return s;
}

void Owner::fromJson(nlohmann::json json)
{
	fullname = json["fullname"].get<std::string>();
	inn = json["inn"].get<std::string>();
	if (json.contains("properties") && json["properties"].is_array()) {
		for (auto& prop : json["properties"]) {
			if (!prop.is_object() || prop.empty()) {
				clog << "Не объект или собственность без параметров пропущены\n";
				continue;
			}

			auto it = prop.begin();
			string key = it.key();
			Property* p;

			try { // PropertySimpleFactory
				p = PropertySimpleFactory::getProperty(key);
			}
			catch (exception e) {
				clog << "Не существует типа собственности " << key << '\n';
				continue;
			}

			//property_type type; // Factory
			//if (key == "Apartment") type = APARTMENT;
			//else if (key == "Car") type = CAR;
			//else if (key == "CountryHouse") type = COUNTRYHOUSE;
			//else {
			//	   clog << "Не существует типа собственности " << key << '\n';
			//     continue;
			//}
			//p = Factory::create(type);

			p->fromJson(it.value());

			properties.push_back(p);
		}
	}
	else {
		clog << "Нет properties или они не являются массивом для " << fullname << '\n';
	}
}

nlohmann::json Owner::toJson()
{
	nlohmann::json json;
	json["fullname"] = fullname;
	json["inn"] = inn;
	json["sumtax"] = calcSumTax();
	vector<nlohmann::json> props;
	for (Property* prop : properties) props.push_back(prop->toJson());
	json["properties"] = props;
	return json;
}