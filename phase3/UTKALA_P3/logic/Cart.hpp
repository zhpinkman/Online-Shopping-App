#ifndef _CART_H_
#define _CART_H_

#include <vector>
#include "CartItem.hpp"

class Cart
{
public:
    void addCartItem(CartItem *cartItem);
    void printCart();
    double getFinalPrice();
    void removeCartItems();
    void restartCart();
    void addCreditToSellers();

private:
    std::vector<CartItem *> cartItems;
};

#endif
