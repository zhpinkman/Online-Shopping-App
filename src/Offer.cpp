#include "Offer.hpp"
#include "Product.hpp"

Offer::Offer(Product* _product, int _id, Seller *_seller, int _amount, double _unitPrice)
{
    product = _product;
    id = _id;
    seller = _seller;
    amount = _amount;
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

int Offer::getAmount()
{
    return amount;
}

bool Offer::idMatches(int _id)
{
    return (id == _id);
}

void Offer::changeOffer(int _amount, double _unitPrice)
{
    amount = _amount;
    unitPrice = _unitPrice;
}

bool Offer::compareByOfferPrice(Offer* first, Offer* second)
{
    return (first->unitPrice == second->unitPrice ? compareByOfferId(first, second) : (first->unitPrice < second->unitPrice));
}

bool Offer::compareByOfferId(Offer* first, Offer* second)
{
    return (first->id < second->id);
}