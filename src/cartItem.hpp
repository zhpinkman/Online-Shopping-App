#include "offer.hpp"

class CartItem
{

private:
    Offer *offer;
    int amount;
    int discount;

public:
    CartItem();
    double getSoldPrice();
};