#ifndef _API_H_
#define _API_H_

// #include "Offer.hpp"

class UserRepository;
class ProductRepository;

class API
{
public:
    API(UserRepository *_userRepository, ProductRepository *_productRepository);
//     // bool isValidDiscountCode(std::string code);
//     // bool isValidDiscountCode(Offer *offer, std::string code);
//     // int useDiscountCode(std::string discountCode);
//     // int getOfferId();
//     // bool canBeAddedToCart(Offer *offer, int amount);

private:
    UserRepository *userRepository;
    ProductRepository *productRepository;
};

#endif