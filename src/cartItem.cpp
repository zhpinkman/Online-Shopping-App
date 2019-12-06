#include "cartItem.hpp"

CartItem::CartItem(Offer *_offer, int _amount, int _discountPercentage)
{
    offer = _offer;
    amount = _amount;
    discountPercentage = _discountPercentage;
}

double CartItem::getSoldPrice()
{
    double initialPrice = offer->getUnitPrice();
    double priceAfterDiscount = (100 - discountPercentage) * initialPrice;
    return priceAfterDiscount;
}