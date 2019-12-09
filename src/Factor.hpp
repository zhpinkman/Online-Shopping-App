#ifndef _FACTOR_H_
#define _FACTOR_H_

#include <vector>
#include "CartItem.hpp"
class Factor
{
public:
    Factor(std::vector<CartItem *> cart);
    double getFinalPrice();

private:
    double productsPrice;
    std::vector<CartItem *> cart;
    double discountAmount;
    double postCost;
    enum status : int;
};

#endif
