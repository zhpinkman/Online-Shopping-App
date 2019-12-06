#include "seller.hpp"
#include "product.hpp"

#include <iostream>

Seller::Seller(int userId, int walletId, std::string username, std::string email, std::string password) : User(id, username, email, password)
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
void Seller::addOffer(Product *p, int amount, int unitPrice)
{
}
bool Seller::checkAuthorization(std::string endpointID) {}