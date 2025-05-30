#pragma once
#include "Owner.h"

class TaxService : public Ijsonio
{
public:
	vector<Owner> owners;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;
};