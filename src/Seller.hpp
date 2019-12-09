#ifndef _SELLER_H_
#define _SELLER_H_

#include "User.hpp"
#include "Wallet.hpp"

class API;
class Product;

class Seller : public User
{
public:
    Seller(API *api, int userId, int walletId, std::string username, std::string email, std::string password);
    void getTransactionHistory(int bound);
    void generateDiscountCode(Offer *offer, int count, int percentage);
    bool checkAuthorization(std::string endpointID);
    void printProducts();
    void addOffer(int productId, double offerUnitPrice, int offerAmount);
    void printOffers();

private:
    Wallet *wallet;
};

#endif
