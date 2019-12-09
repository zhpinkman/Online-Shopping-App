#include "CartItem.hpp"
#include <iostream>
using namespace std;

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

double CartItem::getInitialPrice()
{
    return offer->getUnitPrice();
}

void CartItem::printCartItem()
{
    cout << offer->getProductId() << SEPERATOR << offer->getProductName() << SEPERATOR
         << offer->getId() << SEPERATOR << offer->getSellerId() << SEPERATOR << getSoldPrice() << endl;
}