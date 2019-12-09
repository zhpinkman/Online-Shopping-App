#include <iostream>
#include <vector>
#include "Seller.hpp"
#include "Product.hpp"
#include "API.hpp"
#include "Tools.hpp"
#include "Discount.hpp"
#include "Offer.hpp"
#include "Exceptions.hpp"
#include "PrintTools.hpp"
using namespace std;

Seller::Seller(API *api, int userId, int walletId, std::string username, std::string email, std::string password) : User(api, userId, username, email, password)
{
}

void Seller::showWallet(int count)
{
    std::vector<double> transactionHistory = wallet->getHistory(count);
    for (double transaction : transactionHistory)
        cout << transaction << '\n';
}

void Seller::generateDiscountCard(int offerId, int discountPercent, int discountNumber)
{
    Offer* offer = api->getOffer(offerId);
    std::vector<Discount *> generatedDiscounts;
    std::string code;

    for (int i = 0; i < discountNumber; i++)
    {
        do
        {
            code = Tools::generateRandomString();
        } while (!api->isValidDiscountCode(code));
        Discount *discount = new Discount(code, discountPercent);
        generatedDiscounts.push_back(discount);
    }

    offer->addDiscount(generatedDiscounts);
}

bool Seller::checkAuthorization(std::string endpointID) {}

void Seller::printProducts()
{
    api->printProducts();
}

void Seller::addOffer(int productId, double offerUnitPrice, int offerAmount)
{
    Product* product = api->getProduct(productId);
    if(product == nullptr)
        throw Bad_Request_Exception();
    else if(product->getOffer(this) != nullptr)
        throw Bad_Request_Exception();
    
    int offerId = api->getOfferId();
    Offer *newOffer = new Offer(product, offerId, this, offerAmount, offerUnitPrice);
    product->addOffer(newOffer);
}

void Seller::printOffers()
{
    PrintTools::printOffersInit();

    vector<Offer*> offers = api->getOffers(this);
    
    for(Offer* offer : offers)
        PrintTools::printOfferInfo(offer);
}

void Seller::changeOffer(int offerId, double offerUnitPrice, int offerAmount)
{
    Offer* offer = api->getOffer(offerId);
    if(offer == nullptr)
        throw Bad_Request_Exception();
    
    offer->changeOffer(offerUnitPrice, offerAmount);
}