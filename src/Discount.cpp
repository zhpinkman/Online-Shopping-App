#include "Discount.hpp"
using namespace std;

Discount::Discount(string _code, int _percentage)
{
    code = _code;
    percentage = _percentage;
    discountStatus = UNUSED;
}

bool Discount::isValidDiscount(string _code)
{
    return code == _code && discountStatus == UNUSED;
}

int Discount::useDiscountCode()
{
    discountStatus = USED;
    return percentage;
}