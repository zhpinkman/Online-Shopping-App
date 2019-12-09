#ifndef _PRINT_TOOLS_H_
#define _PRINT_TOOLS_H_

#include "Offer.hpp"
#include "Product.hpp"

class PrintTools
{
public:
    static void printOffersInit();
    static void printOfferInfo(Offer* offer);
    static void printOffersInitBuyer();
    static void printOfferInfoBuyer(Offer* offer);
    static void printProductsInit();
    static void printProductInfo(Product* product);
};

#endif