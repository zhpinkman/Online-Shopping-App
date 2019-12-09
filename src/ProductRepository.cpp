#include <iostream>
#include "ProductRepository.hpp"
#include "Offer.hpp"
#include "constants.hpp"
#include "Exceptions.hpp"
#include "Mobile.hpp"
#include "TV.hpp"
#include "Car.hpp"
using namespace std;

ProductRepository::ProductRepository()
{
    maxOfferId = 1;
    maxProductId = 1;
}

Product* ProductRepository::getProduct(int productId)
{
    Product *product = nullptr;
    for (Product *currProduct : products)
    {
        if (currProduct->productIdMatches(productId))
        {
            product = currProduct;
            break;
        }
    }
    return product;
}

int ProductRepository::getNextOfferId()
{
    return maxOfferId++;
}

int ProductRepository::getNextProductId()
{
    return maxProductId++;
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

void ProductRepository::addProduct(std::string type, const std::vector<std::string> &info)
{
    Product* newProduct;

    if(type == MOBILE_TYPE)
        newProduct = new Mobile(getNextProductId(), info);
    else if(type == TV_TYPE)
        newProduct = new Mobile(getNextProductId(), info);
    else if(type == CAR_TYPE)
        newProduct = new Mobile(getNextProductId(), info);
    else
        throw Bad_Request_Exception();

    products.push_back(newProduct);
}

void ProductRepository::printProducts()
{
    cout << PRODUCT_ID <<  OUTPUT_SEPARATOR << PRODUCT_NAME << '\n';
    for(Product* product : products)
    {
        int productId = product->getId();
        string productName = product->getName();
        cout << productId << SPACE << productName << '\n';
    }
}

vector<Offer*> ProductRepository::getOffers(Seller* seller)
{
    vector<Offer*> result;

    for(Product* product : products)
    {
        Offer* offer = product->getOffer(seller);
        if(offer != nullptr)
            result.push_back(offer);
    }

    return result;
}

Offer* ProductRepository::getOffer(int offerId)
{
    for(Product* product : products)
    {
        Offer* offer = product->getOffer(offerId);
        if(offer != nullptr)
            return offer;
    }
    
    return nullptr;
}