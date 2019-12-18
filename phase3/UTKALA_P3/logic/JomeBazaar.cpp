#include <iostream>
#include "JomeBazaar.hpp"
#include "Buyer.hpp"
#include "Seller.hpp"
#include "Admin.hpp"
#include "Tools.hpp"
#include "Exceptions.hpp"
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
    if (loggedInUser == nullptr)
        throw Permission_Exception();
}

void JomeBazaar::signup(string email, string username, string password, UserType userType)
{
    User *newUser;
    User *user = userRepository->getUser(email);
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
        cout << OK << '\n';
    }
    else
        throw Bad_Request_Exception();
}

void JomeBazaar::login(string email, string password)
{
    User *user = userRepository->getUser(email);
    if (user != nullptr)
    {
        if (user->passwordMatches(password))
        {
            loggedInUser = user;
            cout << OK << '\n';
        }
        else
        {
            throw Bad_Request_Exception();
        }
    }
    else
    {
        throw Bad_Request_Exception();
    }
}

void JomeBazaar::logout()
{
    if (loggedInUser != nullptr)
    {
        loggedInUser->logout();
        loggedInUser = nullptr;
        cout << OK << '\n';
    }
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

void JomeBazaar::offers(string order, string field)
{
    checkLoggedIn();
    loggedInUser->printAllOffers(order, field);
}

void JomeBazaar::offersOnProduct(int productId)
{
    checkLoggedIn();
    loggedInUser->printOffersOnProduct(productId);
}

void JomeBazaar::productDetail(int productId)
{
    checkLoggedIn();
    loggedInUser->productDetail(productId);
}

void JomeBazaar::comments(int productId)
{
    checkLoggedIn();
    loggedInUser->comments(productId);
}

void JomeBazaar::addToCart(int offerId, int amount, string discountCode)
{
    checkLoggedIn();
    loggedInUser->addToCart(offerId, amount, discountCode);
}

void JomeBazaar::generateDiscountCard(int offerId, int discountPercent, int discountNumber)
{
    checkLoggedIn();
    loggedInUser->generateDiscountCard(offerId, discountPercent, discountNumber);
}

void JomeBazaar::wallet(int count)
{
    checkLoggedIn();
    loggedInUser->showWallet(count);
}

void JomeBazaar::cart()
{
    checkLoggedIn();
    loggedInUser->printCart();
}

void JomeBazaar::chargeWallet(double amount)
{
    checkLoggedIn();
    loggedInUser->chargeWallet(amount);
}

void JomeBazaar::comment(int productId, string comment)
{
    checkLoggedIn();
    loggedInUser->addComment(productId, comment);
}

void JomeBazaar::compare(int productId1, int productId2)
{
    checkLoggedIn();
    loggedInUser->compare(productId1, productId2);
}

void JomeBazaar::submitCart()
{
    checkLoggedIn();
    loggedInUser->submitCart();
}

void JomeBazaar::getOrdersHistory(int count)
{
    checkLoggedIn();
    loggedInUser->getOrdersHistory(count);
}