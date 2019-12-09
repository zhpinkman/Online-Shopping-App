#include <iostream>
#include <utility>
#include "Buyer.hpp"
#include "CartItem.hpp"
#include "constants.hpp"
#include "PrintTools.hpp"
#include "Exceptions.hpp"
using namespace std;

Buyer::Buyer(API *api, int userId, int walletId, std::string username, std::string email, std::string password) : User(api, userId, username, email, password)
{
}

void Buyer::addToCart(int offerId, int amount, string discountCode = "")
{
    Offer* offer = api->getOffer(offerId);

    if ((api->isValidDiscountCode(offer, discountCode) || discountCode == "") && api->canBeAddedToCart(offer, amount))
    {
        int discountPercentage = 0;
        if (discountCode != "")
            discountPercentage = api->useDiscountCode(discountCode);
        CartItem* cartItem = new CartItem(offer, amount, discountPercentage);
        cart.push_back(cartItem);
    }
    else
    {
       throw Bad_Request_Exception();
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

void Buyer::productDetail(int productId)
{
    Product* product = api->getProduct(productId);
    string productInfo = product->getProductInfo();

    cout << productInfo << '\n';
}

void Buyer::comments(int productId)
{
    Product* product = api->getProduct(productId);
    vector< pair<User*, string> > comments = product->getComments();

    cout << product->getName() << '\n';
    for(pair<User*, string> comment : comments)
    {
        User* user = comment.first;
        string commentMessage = comment.second;
        cout << user->getUsername() << OUTPUT_SEPARATOR << commentMessage << '\n';
    }
}