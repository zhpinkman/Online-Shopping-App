#include "discount.hpp"

Discount::Discount(std::string _code, int _percentage)
{
    code = _code;
    percentage = _percentage;
    discountStatus = UNUSED;
}

bool Discount::isValidDiscount(std::string _code)
{
    return code == _code && discountStatus == UNUSED;
}

int Discount::useDiscountCode()
{
    discountStatus = USED;
    return percentage;
}