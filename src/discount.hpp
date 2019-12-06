#include <string>
#include "constants.hpp"

class Discount
{
private:
    std::string code;
    DiscountStatus discountStatus;
    int percentage;

public:
    Discount(std::string code, int percentage);
    bool doesCodesMatches(std::string code);
};
