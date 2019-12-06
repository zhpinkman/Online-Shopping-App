#include "buyer.hpp"
#include <iostream>
#include "cartItem.hpp"
#include "constants.hpp"

Buyer::Buyer(Api *api, Tools *tools, int userId, int walletId, std::string username, std::string email, std::string password) : User(api, tools, userId, username, email, password)
{
}

bool Buyer::addToCart(Offer *offer, int amount, std::string discountCode = "")
{
    if (api->isValidDiscountCode(offer, discountCode) || discountCode == "")
    {
        int discountPercentage;
        if (discountCode != "")
            discountPercentage = api->useDiscountCode(discountCode);
        discountPercentage = 0;
        CartItem *cartItem = new CartItem(offer, amount, discountPercentage);
        std::cout << OK << std::endl;
        return SUCCESS;
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
        return FAILED;
    }
}
bool Buyer::submitCart()
{
    Factor *factor = new Factor(cart);
    double finalPrice = factor->getFinalPrice();
    if (wallet->withdraw(finalPrice))
    {

        std::cout << OK << std::endl;
        return SUCCESS;
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
        return FAILED;
    }
}
std::vector<std::string> Buyer::getOrdersHistory(int bound)
{
    for (int i = 0; i < orders.size(); i++)
    {
        std::cout << orders[i].first->getProductId() << SEPERATOR << orders[i].first->getProductName() << SEPERATOR;
        std::cout << orders[i].first->getId() << SEPERATOR << orders[i].first->getSellerId() << SEPERATOR;
        std::cout << orders[i].second->getSoldPrice() << std::endl;
    }
}
std::vector<std::string> Buyer::getTransactionHistory(int bound)
{
    std::vector<double> transactionHistory = wallet->getHistory(bound);
    for (double transaction : transactionHistory)
    {
        std::cout << transaction << std::endl;
    }
}
bool Buyer::chargeWallet(double amount)
{
    wallet->charge(amount);
}
std::vector<std::string> Buyer::getCoupons() {}
bool Buyer::payFactor(Factor *factor) {}
bool Buyer::checkAuthorization(std::string endpointID) {}