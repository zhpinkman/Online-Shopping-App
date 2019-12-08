#ifndef _BUYER_H_
#define _BUYER_H_

#include "User.hpp"
#include "Wallet.hpp"
#include "Offer.hpp"
#include "Factor.hpp"

class CartItem;
class API;

class Buyer : public User
{
public:
    Buyer(API *api, int userId, int walletId, std::string username, std::string email, std::string password);
    // bool addToCart(Offer *offer, int amount, std::string discountCode);
    // bool submitCart();
    // std::vector<std::string> getOrdersHistory(int bound);
    // std::vector<std::string> getTransactionHistory(int bound);
    // bool chargeWallet(double amount);
    // std::vector<std::string> getCoupons();
    // bool payFactor(Factor *factor);
    // bool checkAuthorization(std::string endpointID);

private:
    Wallet *wallet;
    // std::vector<CartItem *> cart;
    // std::vector<std::pair<Offer*, CartItem*>> orders;
};

#endif