#pragma once
#include "Owner.h"

class TaxService : public Ijsonio
{
public:
	void fromJson(nlohmann::json json);
	nlohmann::json toJson();

	vector<double> calcEachSumTax(vector<Property*>);
};