#include "discount.hpp"

Discount::Discount(std::string _code, int _percentage)
{
    code = _code;
    percentage = _percentage;
}

bool Discount::doesCodesMatches(std::string _code)
{
    return code == _code;
}