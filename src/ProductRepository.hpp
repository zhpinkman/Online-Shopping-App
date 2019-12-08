#ifndef _PRODUCT_REPOSITORY_H
#define _PRODUCT_REPOSITORY_H

#include <vector>
#include <string>
#include "Product.hpp"
#include "Discount.hpp"

class Offer;

class ProductRepository
{
public:
    ProductRepository();
    Product *getProduct(std::string productName);
    bool isDiscountCodeUnique(std::string code);
    bool isDiscountCodeValid(Offer *offer, std::string code);
    int getNextOfferId();
    int useDiscountCode(std::string discountCode);
    bool canBeAddedToCart(Offer *offer, int amount);
    void addProduct(std::string type, const std::vector<std::string> &info);

private:
    std::vector<Product *> products;
    std::vector<Discount *> discounts;
    int maxOfferId;
    int maxProductId;
        
    int getNextProductId();
};

#endif