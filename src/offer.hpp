#include "discount.hpp"
#include "seller.hpp"
#include <vector>

class Seller;

class Offer
{
private:
    int id;
    Seller *seller;
    int count;
    int unitPrice;
    std::vector<Discount *> discounts;

public:
    Offer();
};
