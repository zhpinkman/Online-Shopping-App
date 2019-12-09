#include <iostream>
#include "PrintTools.hpp"
#include "constants.hpp"
using namespace std;

void PrintTools::printOffersInit()
{
    cout << PRODUCT_ID << OUTPUT_SEPARATOR << OFFER_ID << OUTPUT_SEPARATOR << OFFER_UNIT_PRICE << OUTPUT_SEPARATOR << OFFER_AMOUNT << '\n';
}

void PrintTools::printOfferInfo(Offer* offer)
{
    int productId = offer->getProductId();
    int offerId = offer->getId();
    double unitPrice = offer->getUnitPrice();
    int amount = offer->getAmount();
    cout << productId << OUTPUT_SEPARATOR << offerId << OUTPUT_SEPARATOR << unitPrice << OUTPUT_SEPARATOR << amount << '\n';
}

void PrintTools::printProductsInit()
{
    cout << PRODUCT_ID <<  OUTPUT_SEPARATOR << PRODUCT_NAME << '\n';
}

void PrintTools::printProductInfo(Product* product)
{
    int productId = product->getId();
    string productName = product->getName();
    cout << productId << OUTPUT_SEPARATOR << productName << '\n';
}

void PrintTools::printOffersInitBuyer()
{
    cout << PRODUCT_ID << OUTPUT_SEPARATOR << PRODUCT_NAME << OUTPUT_SEPARATOR << OFFER_ID << OUTPUT_SEPARATOR << OFFER_UNIT_PRICE << OUTPUT_SEPARATOR << OFFER_AMOUNT << '\n';
}

void PrintTools::printOfferInfoBuyer(Offer* offer)
{
    int productId = offer->getProductId();
    string productName = offer->getProductName();
    int offerId = offer->getId();
    double unitPrice = offer->getUnitPrice();
    int amount = offer->getAmount();
    cout << productId << OUTPUT_SEPARATOR << productName << OUTPUT_SEPARATOR << offerId << OUTPUT_SEPARATOR << unitPrice << OUTPUT_SEPARATOR << amount << '\n';
}