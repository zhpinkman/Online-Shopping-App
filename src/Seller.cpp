#include "Seller.hpp"
#include "Product.hpp"
// #include "system.hpp"
#include "API.hpp"
#include "Tools.hpp"
#include "Discount.hpp"
#include "Offer.hpp"
#include <iostream>

Seller::Seller(API *api, int userId, int walletId, std::string username, std::string email, std::string password) : User(api, userId, username, email, password)
{
}

void Seller::getTransactionHistory(int bound)
{
    std::vector<double> transactionHistory = wallet->getHistory(bound);
    for (double transaction : transactionHistory)
    {
        std::cout << transaction << std::endl;
    }
}
void Seller::generateDiscountCode(Offer *offer, int count, int percentage)
{
    std::vector<Discount *> generatedDiscounts;
    std::string code;
    for (int i = 0; i < count; i++)
    {
        do
        {
            code = Tools::generateRandomString();
        } while (!api->isValidDiscountCode(code));
        Discount *discount = new Discount(code, percentage);
        generatedDiscounts.push_back(discount);
    }
    offer->addDiscount(generatedDiscounts);
}
void Seller::addOffer(Product *p, int count, int unitPrice)
{
    int offerId = api->getOfferId();
    Offer *newOffer = new Offer(offerId, this, count, unitPrice);
    p->addOffer(newOffer);
}
bool Seller::checkAuthorization(std::string endpointID) {}