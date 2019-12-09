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

private:
    API* api;
    User* loggedInUser;
    UserRepository* userRepository;
    ProductRepository* productRepository;

    void checkLoggedIn();
};

#endif