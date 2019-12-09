#include "Cart.hpp"
#include "constants.hpp"
using namespace std;

void Cart::addCartItem(CartItem* cartItem)
{
    cartItems.push_back(cartItem);
}