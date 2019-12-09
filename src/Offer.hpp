#ifndef _OFFER_H_
#define _OFFER_H_

#include "Discount.hpp"
#include "Seller.hpp"
#include <vector>

class Seller;
class Product;

class Offer
{
public:
    Offer(Product* _product, int _id, Seller *_seller, int _amount, double _unitPrice);
    void addDiscount(std::vector<Discount *> discounts);
    int getProductId();
    std::string getProductName();
    int getId();
    int getSellerId();
    double getUnitPrice();
    bool hasDiscountCode(std::string code);
    bool sellerMatches(Seller* _seller);
    int getAmount();

private:
    int id;
    Seller *seller;
    int amount;
    double unitPrice;
    std::vector<Discount *> discounts;
    Product *product;
};

#endif