#ifndef _DISCOUNT_H_
#define _DISCOUNT_H_

#include <string>
#include "constants.hpp"

class Discount
{
public:
    Discount(std::string code, int percentage);
    bool isValidDiscount(std::string code);
    int useDiscountCode();
    
private:
    std::string code;
    DiscountStatus discountStatus;
    int percentage;
};

#endif
