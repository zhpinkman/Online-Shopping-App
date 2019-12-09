#include <iostream>
#include "JomeBazaar.hpp"
#include "Buyer.hpp"
#include "Seller.hpp"
#include "Admin.hpp"
#include "Tools.hpp"
#include "Exceptions.hpp"
#include <iostream>

using namespace std;

JomeBazaar::JomeBazaar()
{
    userRepository = new UserRepository();
    productRepository = new ProductRepository();
    api = new API(userRepository, productRepository);
    userRepository->addUser(new Admin(api));
    loggedInUser = nullptr;
}

void JomeBazaar::checkLoggedIn()
{
    if(loggedInUser == nullptr)
        throw Permission_Exception();
}

void JomeBazaar::signup(std::string email, std::string username, std::string password, UserType userType)
{
    User* newUser;
    User* user = userRepository->getUser(email);
    if (user == nullptr)
    {
        int newUserId = userRepository->getNextUserId();
        int newWalletId = userRepository->getNextWalletId();
        switch (userType)
        {
            case BUYER:
                newUser = new Buyer(api, newUserId, newWalletId, username, email, password);
                userRepository->addUser(newUser);
                break;
            case SELLER:
                newUser = new Seller(api, newUserId, newWalletId, username, email, password);
                userRepository->addUser(newUser);
                break;
            default:
                throw Bad_Request_Exception();
        }
        loggedInUser = newUser;
    }
    else
        throw Bad_Request_Exception();
}
void JomeBazaar::login(std::string email, std::string password)
{
    User *user = userRepository->getUser(email);
    if (user != nullptr)
        if (user->passwordMatches(password))
            loggedInUser = user;
        else
            throw Bad_Request_Exception();
    else
        throw Bad_Request_Exception();
}

void JomeBazaar::logout()
{
    if (loggedInUser != nullptr)
        loggedInUser = nullptr;
    else
        throw Permission_Exception();
}

void JomeBazaar::importProduct(string type, string filePath)
{
    checkLoggedIn();
    loggedInUser->importProductsFromCSV(type, filePath);    
}

void JomeBazaar::getProducts()
{
    checkLoggedIn();
    loggedInUser->printProducts();
}

void JomeBazaar::offer(int productId, double offerUnitPrice, int offerAmount)
{
    checkLoggedIn();
    loggedInUser->addOffer(productId, offerUnitPrice, offerAmount);
}

void JomeBazaar::myOffers()
{
    checkLoggedIn();
    loggedInUser->printOffers();
}

void JomeBazaar::changeOffer(int offerId, double offerUnitPrice, int offerAmount)
{
    checkLoggedIn();
    loggedInUser->changeOffer(offerId, offerUnitPrice, offerAmount);
}

void JomeBazaar::offers(std::string order, std::string field)
{
    checkLoggedIn();
    loggedInUser->printAllOffers(order, field);
}