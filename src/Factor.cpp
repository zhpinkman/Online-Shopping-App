#include "Factor.hpp"
using namespace std;

Factor::Factor(vector<CartItem *> _cart)
{
    cart = _cart;
}

double Factor::getFinalPrice()
{
    double result;

    for (int i = 0; i < cart.size(); i++)
        result += cart[i]->getSoldPrice();
    
    return result;
}