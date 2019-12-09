#include "User.hpp"
#include "constants.hpp"
#include "Exceptions.hpp"
using namespace std;

User::User(API*_api, int _id, std::string _username, std::string _email, std::string _password)
{
    api = _api;
    username = _username;
    email = _email;
    password = _password;
}

std::string User::getUsername()
{
    return username;
}

bool User::checkAuthorization(std::string endpointID)
{
    // TODO
}

bool User::passwordMatches(std::string _password)
{
    return password == _password;
}

bool User::emailMatches(std::string _email)
{
    return email == _email;
}

int User::getId()
{
    return id;
}

void User::importProductsFromCSV(string type, string filePath)
{
    throw Permission_Exception();
}

void User::printProducts()
{
    throw Permission_Exception();
}

void User::addOffer(int productId, double offerUnitPrice, int offerAmount)
{
    throw Permission_Exception();
}

void User::printOffers()
{
    throw Permission_Exception();
}

void User::changeOffer(int offerId, double offerUnitPrice, int offerAmount)
{
    throw Permission_Exception();
}

void User::printAllOffers(std::string order, std::string field)
{
    throw Permission_Exception();
}

void User::printOffersOnProduct(int productId)
{
    throw Permission_Exception();
}

void User::productDetail(int productId)
{
    throw Permission_Exception();
}

void User::comments(int productId)
{
    throw Permission_Exception();void comments(int productId);
}

void User::addToCart(int offerId, int amount, string discountCode)
{
    throw Permission_Exception();
}

void User::generateDiscountCard(int offerId, int discountPercent, int discountNumber)
{
    throw Permission_Exception();
}

void User::showWallet(int count)
{
    throw Permission_Exception();
}