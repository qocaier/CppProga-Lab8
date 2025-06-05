#include "TaxService.h"

void TaxService::fromJson(nlohmann::json json)
{
	Owner ownr;
	for (auto& own : json) {
		ownr = Owner();
		ownr.fromJson(own);
		owners.push_back(ownr);
	}
}

nlohmann::json TaxService::toJson()
{
	vector<nlohmann::json> taxs;
	for (Owner ownr : owners) taxs.push_back(ownr.toJson());
	return taxs;
}

void TaxService::fromXml(const pugi::xml_node& xml)
{
	Owner ownr;
	for (auto& own : xml.children()) {
		ownr = Owner();
		ownr.fromXml(own);
		owners.push_back(ownr);
	}
}

void TaxService::toXml(pugi::xml_node& xml)
{
	for (Owner ownr : owners) ownr.toXml(xml);
}