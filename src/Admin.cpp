#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Admin.hpp"
#include "Tools.hpp"
#include "constants.hpp"
#include "Offer.hpp"
#include "PrintTools.hpp"
using namespace std;

Admin::Admin(API* _api) : User(_api, USER_ID_BEGIN, ADMIN_USERNAME, ADMIN_EMAIL, ADMIN_PASSWORD) {}

void Admin::importProductsFromCSV(string type, string filePath)
{
    ifstream file = Tools::openCSVFile(filePath);
    vector< vector<string> > products = Tools::parseCSVFile(file);
    file.close();

    for(int i = 1; i < products.size(); i++)
        api->addProduct(type, products[i]);
}

void Admin::printAllOffers(string order, string field)
{
    PrintTools::printOffersInit();
    
    vector<Offer*> offers = api->getOffers();

    if(field == OFFER_PRICE)
        sort(offers.begin(), offers.end(), Offer::compareByOfferPrice);
    else if(field == OFFER_ID)
        sort(offers.begin(), offers.end(), Offer::compareByOfferId);

    if(order == ASCEND)
        for(int i = 0; i < offers.size(); i++)
            PrintTools::printOfferInfo(offers[i]);
    else if(order == DESCEND)
        for(int i = offers.size() - 1; i >= 0; i--)
            PrintTools::printOfferInfo(offers[i]);
}