#include <vector>
#include "cartItem.hpp"

class Factor
{
private:
    double productsPrice;
    std::vector<CartItem *> cart;
    double discountAmount;
    double postCost;
    enum status : int;

public:
    Factor(std::vector<CartItem *> cart);
    double getFinalPrice();
};