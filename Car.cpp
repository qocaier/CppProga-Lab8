#include "Car.h"

double Car::calcTax()
{
    if (horsepower < LOW_HORSEPOWER) return worth * CAR_TAX;
    if (horsepower > HIGH_HORSEPOWER) return worth * CAR_LUXURY_TAX;
    return worth * CAR_TRUCK_TAX;
}