#include "productRepository.hpp"

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