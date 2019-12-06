#include "discount.hpp"
#include "seller.hpp"
#include <vector>

class Seller;
class Product;

class Offer
{
private:
    int id;
    Seller *seller;
    int count;
    int unitPrice;
    std::vector<Discount *> discounts;
    Product *product;

public:
    Offer(int id, Seller *seller, int count, int unitPrice);
    void addDiscount(std::vector<Discount *> discounts);
    int getProductId();
    std::string getProductName();
    int getId();
    int getSellerId();
    double getUnitPrice();
    bool hasDiscountCode(std::string code);
};
