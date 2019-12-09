#ifndef _JOME_BAZAAR_H_
#define _JOME_BAZAAR_H_

#include "API.hpp"
#include "User.hpp"
#include "UserRepository.hpp"
#include "ProductRepository.hpp"
#include "constants.hpp"

class JomeBazaar
{
public:
    JomeBazaar();
    void signup(std::string email, std::string username, std::string password, UserType userType);
    void login(std::string email, std::string password);
    void logout();
    void importProduct(std::string type, std::string filePath);
    void getProducts();
    void offer(int productId, double offerUnitPrice, int offerAmount);
    void myOffers();
    void changeOffer(int offerId, double offerUnitPrice, int offerAmount);
    void offers(std::string order, std::string field);
    void offersOnProduct(int productId);
    void productDetail(int productId);
    void comments(int productId);
    void addToCart(int offerId, int amount, std::string discountCode);
    void generateDiscountCard(int offerId, int discountPercent, int discountNumber);
    void wallet(int count);
    void cart();
    void chargeWallet(double amount);
    void comment(int productId, std::string comment);
    void compare(int productId1, int productId2);

private:
    API* api;
    User* loggedInUser;
    UserRepository* userRepository;
    ProductRepository* productRepository;
    void checkLoggedIn();
};

#endif