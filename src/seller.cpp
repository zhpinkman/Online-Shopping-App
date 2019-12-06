#include "seller.hpp"
#include "product.hpp"
#include "system.hpp"
#include "api.hpp"
#include <iostream>

Seller::Seller(Api *api, int userId, int walletId, std::string username, std::string email, std::string password) : User(api, userId, username, email, password)
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
}
void Seller::addOffer(Product *p, int count, int unitPrice)
{
    int offerId = api->getOfferId();
    Offer *newOffer = new Offer(offerId, this, count, unitPrice);
    p->addOffer(newOffer);
}
bool Seller::checkAuthorization(std::string endpointID) {}