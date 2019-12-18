#ifndef _FACTOR_H_
#define _FACTOR_H_

#include <vector>
#include "CartItem.hpp"
#include "Cart.hpp"
class Factor
{
public:
    Factor(Cart *cart);
    double getFinalPrice();

private:
    double productsPrice;
    Cart *cart;
    double discountAmount;
    double postCost;
    enum status : int;
};

#endif
