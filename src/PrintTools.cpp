#include <iostream>
#include "PrintTools.hpp"
#include "constants.hpp"
using namespace std;

void PrintTools::printOffersInit()
{
    cout << PRODUCT_DETAIL << OUTPUT_SEPARATOR << OFFER_ID << OUTPUT_SEPARATOR << OFFER_UNIT_PRICE << OUTPUT_SEPARATOR << OFFER_AMOUNT << '\n';
}

void PrintTools::printOfferInfo(Offer* offer)
{
    int productId = offer->getProductId();
    int offerId = offer->getId();
    double unitPrice = offer->getUnitPrice();
    int amount = offer->getAmount();
    cout << productId << OUTPUT_SEPARATOR << offerId << OUTPUT_SEPARATOR << unitPrice << OUTPUT_SEPARATOR << amount << '\n';
}