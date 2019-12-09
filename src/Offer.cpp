#include "Offer.hpp"
#include "Product.hpp"

Offer::Offer(int _id, Seller *_seller, int _count, double _unitPrice)
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

int Offer::getProductId()
{
    return product->getId();
}

std::string Offer::getProductName()
{
    return product->getName();
}

int Offer::getId()
{
    return id;
}

int Offer::getSellerId()
{
    // return seller->getId();
}

double Offer::getUnitPrice()
{
    return unitPrice;
}

bool Offer::hasDiscountCode(std::string code)
{
    for (Discount *discount : discounts)
    {
        if (discount->isValidDiscount(code))
        {
            return true;
        }
    }
    return false;
}

bool Offer::sellerMatches(Seller* _seller)
{
    return (seller == _seller);
}