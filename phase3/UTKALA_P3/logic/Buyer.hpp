#ifndef _BUYER_H_
#define _BUYER_H_

#include <vector>
#include "User.hpp"
#include "Wallet.hpp"
#include "Offer.hpp"
#include "Factor.hpp"
#include "Cart.hpp"

class API;
class CartItem;

class Buyer : public User
{
public:
    Buyer(API *api, int userId, int walletId, std::string username, std::string email, std::string password);
    void submitCart();
    void getOrdersHistory(int bound);
    std::vector<std::string> getTransactionHistory(int bound);
    void chargeWallet(double amount);
    void printProducts();
    void printOffersOnProduct(int productId);
    void productDetail(int productId);
    void comments(int productId);
    void addToCart(int offerId, int amount, std::string discountCode);
    void showWallet(int count);
    void addComment(int productId, std::string comment);
    void compare(int productId1, int productId2);
    void printCart();
    void logout();

private:
    Cart *cart;
    Wallet *wallet;
    std::vector<Cart *> orders;
};

#endif