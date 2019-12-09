#include <iostream>
#include "Buyer.hpp"
#include "CartItem.hpp"
#include "constants.hpp"
#include "PrintTools.hpp"
using namespace std;

Buyer::Buyer(API *api, int userId, int walletId, std::string username, std::string email, std::string password) : User(api, userId, username, email, password)
{
}

bool Buyer::addToCart(Offer *offer, int amount, std::string discountCode = "")
{
    if ((api->isValidDiscountCode(offer, discountCode) || discountCode == "") && api->canBeAddedToCart(offer, amount))
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

void Buyer::printProducts()
{
    api->printProducts();
}

void Buyer::printOffersOnProduct(int productId)
{
    Product* product = api->getProduct(productId);
    vector <Offer*> offers = product->getOffers();

    PrintTools::printOffersInitBuyer();

    for(Offer* offer : offers)
        PrintTools::printOfferInfoBuyer(offer);
}