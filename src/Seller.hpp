#ifndef _SELLER_H_
#define _SELLER_H_

#include "User.hpp"
#include "Wallet.hpp"

class API;
class Product;

class Seller : public User
{
// private:
//     Wallet *wallet;

public:
    Seller(API *api, int userId, int walletId, std::string username, std::string email, std::string password);
//     void getTransactionHistory(int bound);
//     void generateDiscountCode(Offer *offer, int count, int percentage);
//     void addOffer(Product *p, int count, int unitPrice);
//     bool checkAuthorization(std::string endpointID);
};

#endif