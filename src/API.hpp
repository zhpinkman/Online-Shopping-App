#ifndef _API_H_
#define _API_H_

#include <vector>
#include <string>
#include "Product.hpp"

class Offer;
class UserRepository;
class ProductRepository;

class API
{
public:
    API(UserRepository *_userRepository, ProductRepository *_productRepository);
    bool isValidDiscountCode(std::string code);
    bool isValidDiscountCode(Offer *offer, std::string code);
    int useDiscountCode(std::string discountCode);
    int getOfferId();
    void checkAvailability(Offer *offer, int amount);
    void addProduct(std::string type, const std::vector<std::string> &info);
    void printProducts();
    std::vector<Offer *> getOffers(Seller *seller);
    Product *getProduct(int productId);
    Offer *getOffer(int offerId);
    std::vector<Offer *> getOffers();

private:
    UserRepository *userRepository;
    ProductRepository *productRepository;
};

#endif