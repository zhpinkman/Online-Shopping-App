#include "product.hpp"

class ProductRepository
{
private:
    std::vector<Product *> products;

public:
    ProductRepository();
    Product *getProduct(std::string productName);
    ProductRepository *getInstance();
};
