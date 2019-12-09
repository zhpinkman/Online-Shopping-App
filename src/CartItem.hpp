#ifndef _CART_ITEM_H_
#define _CART_ITEM_H_

#include "Offer.hpp"

class CartItem
{
public:
    CartItem(Offer *offer, int amount, int discountPercentage);
    double getSoldPrice();
    double getInitialPrice();
    
private:
    Offer *offer;
    int amount;
    int discountPercentage;
};

#endif