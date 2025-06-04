#pragma once
#include "Owner.h"

class TaxService : public Ijsonio, public Ixmlio
{
public:
	vector<Owner> owners;

	void fromJson(nlohmann::json json) override;
	nlohmann::json toJson() override;
	void fromXml(const pugi::xml_node& xml) override;
	void toXml(pugi::xml_node& xml) override;
};