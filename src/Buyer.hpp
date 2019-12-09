#ifndef _BUYER_H_
#define _BUYER_H_

#include "User.hpp"
#include "Wallet.hpp"
#include "Offer.hpp"
#include "Factor.hpp"
#include "Cart.hpp"

class CartItem;
class API;

class Buyer : public User
{
public:
    Buyer(API *api, int userId, int walletId, std::string username, std::string email, std::string password);
    bool submitCart();
    std::vector<std::string> getOrdersHistory(int bound);
    std::vector<std::string> getTransactionHistory(int bound);
    void chargeWallet(double amount);
    std::vector<std::string> getCoupons();
    bool payFactor(Factor *factor);
    bool checkAuthorization(std::string endpointID);
    void printProducts();
    void printOffersOnProduct(int productId);
    void productDetail(int productId);
    void comments(int productId);
    void addToCart(int offerId, int amount, std::string discountCode);
    void printCart();
    void showWallet(int count);
    void addComment(int productId, std::string comment);
    void compare(int productId1, int productId2);


private:
    Wallet* wallet;
    Cart* cart;
    std::vector<Cart*> orders;
};

#endif