#include "product.hpp"
#include "discount.hpp"

class ProductRepository
{
private:
    std::vector<Product *> products;
    std::vector<Discount *> discounts;
    int maxOfferId;

public:
    ProductRepository();
    Product *getProduct(std::string productName);
    bool isDiscountCodeUnique(std::string code);
    // ProductRepository *getInstance();
    int getNextOfferId();
};
