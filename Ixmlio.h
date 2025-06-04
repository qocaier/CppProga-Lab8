#pragma once
#include "pugixml.hpp"

class Ixmlio {
public:
	virtual void fromXml(const pugi::xml_node& xml) = 0;
	virtual void toXml(pugi::xml_node& xml) = 0;

	virtual ~Ixmlio() {};
};