#include "offer.hpp"

Offer::Offer(int _id, Seller *_seller, int _count, int _unitPrice)
{
    id = _id;
    seller = _seller;
    count = _count;
    unitPrice = _unitPrice;
}

void Offer::addDiscount(std::vector<Discount *> _discounts)
{
    discounts = _discounts;
}
