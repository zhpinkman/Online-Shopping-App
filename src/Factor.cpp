#include "Factor.hpp"
using namespace std;

Factor::Factor(Cart *_cart)
{
    cart = _cart;
}

double Factor::getFinalPrice()
{
    return cart->getFinalPrice();
}