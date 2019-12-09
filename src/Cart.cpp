#include "Cart.hpp"
#include "constants.hpp"
using namespace std;

void Cart::addCartItem(CartItem *cartItem)
{
    cartItems.push_back(cartItem);
}

double Cart::getFinalPrice()
{
    double result = 0;
    for (int i = 0; i < cartItems.size(); i++)
    {
        result += cartItems[i]->getSoldPrice();
    }
    return result;
}