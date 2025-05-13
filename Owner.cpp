#include "Owner.h"
#include <stdexcept>

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