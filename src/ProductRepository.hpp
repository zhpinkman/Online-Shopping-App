#ifndef _PRODUCT_REPOSITORY_H
#define _PRODUCT_REPOSITORY_H

#include <vector>
#include <string>
#include "Product.hpp"
#include "Discount.hpp"

class Offer;
class Seller;

class ProductRepository
{
public:
    ProductRepository();
    Product* getProduct(int productId);
    bool isDiscountCodeUnique(std::string code);
    bool isDiscountCodeValid(Offer *offer, std::string code);
    int getNextOfferId();
    int useDiscountCode(std::string discountCode);
    bool canBeAddedToCart(Offer *offer, int amount);
    void addProduct(std::string type, const std::vector<std::string> &info);
    void printProducts();
    std::vector<Offer*> getOffers(Seller* seller);
    Offer* getOffer(int offerId);

private:
    std::vector<Product *> products;
    std::vector<Discount *> discounts;
    int maxOfferId;
    int maxProductId;
        
    int getNextProductId();
};

#endif