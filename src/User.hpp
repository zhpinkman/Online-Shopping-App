#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "API.hpp"

class User
{
public:
    User(API* _api, int _id, std::string _username, std::string _email, std::string _password);
    int getId();
    std::string getUsername();
    bool emailMatches(std::string email);
    bool passwordMatches(std::string password);
    bool checkAuthorization(std::string endpointID);

    virtual void importProductsFromCSV(std::string type, std::string filePath);
    virtual void printProducts();
    virtual void addOffer(int productId, double offerUnitPrice, int offerAmount);
    virtual void printOffers();
    virtual void changeOffer(int offerId, double offerUnitPrice, int offerAmount);
    virtual void printAllOffers(std::string order, std::string field);
    virtual void printOffersOnProduct(int productId);
    virtual void productDetail(int productId);
    virtual void comments(int productId);
    virtual void addToCart(int offerId, int amount, std::string discountCode);
    virtual void generateDiscountCard(int offerId, int discountPercent, int discountNumber);

private:
    int id;
    std::string username;
    std::string password;
    std::string email;

protected:
    API* api;
};

#endif