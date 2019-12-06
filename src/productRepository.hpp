#include "product.hpp"
#include "discount.hpp"

class ProductRepository
{
private:
    std::vector<Product *> products;
    std::vector<Discount *> discounts;
public:
    ProductRepository();
    Product *getProduct(std::string productName);
    ProductRepository *getInstance();
};
