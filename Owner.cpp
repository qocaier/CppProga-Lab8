#include "Owner.h"
#include "PropertyFactory.h"
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
			//if (key == "apartment") type = APARTMENT;
			//else if (key == "car") type = CAR;
			//else if (key == "countryhouse") type = COUNTRYHOUSE;
			//else {
			//	   clog << "Не существует типа собственности " << key << '\n';
			//     continue;
			//}
			//p = Factory::create(type);

			/*if (key == "apartment") p = PropertyFactory::create<Apartment>(); // PropertyFactory
			else if (key == "car") p = PropertyFactory::create<Car>();
			else if (key == "countryhouse") p = PropertyFactory::create<CountryHouse>();
			else {
				 clog << "Не существует типа собственности " << key << '\n';
				 continue;
			}*/

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

void Owner::fromXml(const pugi::xml_node& xml)
{
	fullname = xml.attribute("fullname").as_string();
	inn = xml.attribute("inn").as_string();
	for (auto& node : xml.children()) {
		string key = node.name();
		Property* p;

		try { // PropertySimpleFactory
			p = PropertySimpleFactory::getProperty(key);
		}
		catch (exception e) {
			clog << "Не существует типа собственности " << key << '\n';
			continue;
		}

		//property_type type; // Factory
		//if (key == "apartment") type = APARTMENT;
		//else if (key == "car") type = CAR;
		//else if (key == "countryhouse") type = COUNTRYHOUSE;
		//else {
		//	   clog << "Не существует типа собственности " << key << '\n';
		//     continue;
		//}
		//p = Factory::create(type);

		//if (key == "apartment") p = PropertyFactory::create<Apartment>(); // PropertyFactory
		//else if (key == "car") p = PropertyFactory::create<Car>();
		//else if (key == "countryhouse") p = PropertyFactory::create<CountryHouse>();
		//else {
		//	 clog << "Не существует типа собственности " << key << '\n';
		//	 continue;
		//}

		p->fromXml(node);

		properties.push_back(p);
	}
}

void Owner::toXml(pugi::xml_node& xml)
{
	pugi::xml_node owner_node = xml.append_child("owner");
	pugi::xml_attribute fullname_attr = owner_node.append_attribute("fullname");
	fullname_attr.set_value(fullname.c_str());

	pugi::xml_attribute inn_attr = owner_node.append_attribute("inn");
	inn_attr.set_value(inn.c_str());

	pugi::xml_attribute tax_attr = owner_node.append_attribute("sumtax");
	tax_attr.set_value(to_string(calcSumTax()).c_str());

	for (Property* prop : properties) prop->toXml(owner_node);
}