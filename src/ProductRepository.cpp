#include "ProductRepository.hpp"
#include "Offer.hpp"
using namespace std;

ProductRepository::ProductRepository()
{
    maxOfferId = 1;
}

Product *ProductRepository::getProduct(std::string productName)
{
    Product *product;
    for (Product *currProduct : products)
    {
        if (currProduct->productNameMatches(productName))
        {
            return currProduct;
        }
    }
    return nullptr;
}

int ProductRepository::getNextOfferId()
{
    return maxOfferId++;
}

bool ProductRepository::isDiscountCodeUnique(std::string code)
{
    for (Discount *discount : discounts)
    {
        if (discount->isValidDiscount(code))
        {
            return false;
        }
    }
    return true;
}

int ProductRepository::useDiscountCode(std::string discountCode)
{
    for (Discount *discount : discounts)
    {
        if (discount->isValidDiscount(discountCode))
        {
            return discount->useDiscountCode();
        }
    }
}

bool ProductRepository::isDiscountCodeValid(Offer *offer, std::string code)
{
    for (Discount *discount : discounts)
    {
        if (discount->isValidDiscount(code) && offer->hasDiscountCode(code))
        {
            return true;
        }
    }
    return false;
}

bool ProductRepository::canBeAddedToCart(Offer *offer, int amount)
{
    // TODO
}