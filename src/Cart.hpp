#ifndef _CART_H_
#define _CART_H_

#include <vector>
#include "CartItem.hpp"

class Cart
{
public:
    void addCartItem(CartItem* cartItem);

private:
    std::vector<CartItem*> cartItems;
};

#endif