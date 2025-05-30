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