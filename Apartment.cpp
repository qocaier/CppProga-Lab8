#include "Apartment.h"

double Apartment::calcTax()
{
    if (square <= LIMIT_Apartment_SQUARE) return worth * Apartment_TAX;
    return worth * Apartment_LUXURY_TAX;
}