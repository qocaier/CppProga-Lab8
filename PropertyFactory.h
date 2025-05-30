#pragma once
#include <type_traits>
#include "Property.h"

class PropertyFactory
{
public:
	template<class T, typename = std::enable_if_t<std::is_base_of<Property, T>::value>>
	static T* create() { return new T(); }
};