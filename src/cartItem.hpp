#include "offer.hpp"

class CartItem
{

private:
    Offer *offer;
    int amount;
    int discountPercentage;

public:
    CartItem(Offer *offer, int amount, int discountPercentage);
    double getSoldPrice();
};