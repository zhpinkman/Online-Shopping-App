#include "API.hpp"
#include "UserRepository.hpp"
#include "ProductRepository.hpp"
using namespace std;

API::API(UserRepository *_userRepository, ProductRepository *_productRepository)
{
    userRepository = _userRepository;
    productRepository = _productRepository;
}

int API::getOfferId()
{
    return productRepository->getNextOfferId();
}

bool API::isValidDiscountCode(string code)
{
    return productRepository->isDiscountCodeUnique(code);
}

int API::useDiscountCode(string discountCode)
{
    return productRepository->useDiscountCode(discountCode);
}

bool API::isValidDiscountCode(Offer *offer, string code)
{
    return productRepository->isDiscountCodeValid(offer, code);
}

void API::checkAvailability(Offer *offer, int amount)
{
    productRepository->checkOfferAvailability(offer, amount);
}

void API::addProduct(string type, const vector<string> &info)
{
    productRepository->addProduct(type, info);
}

void API::printProducts()
{
    productRepository->printProducts();
}

Product *API::getProduct(int productId)
{
    return productRepository->getProduct(productId);
}

vector<Offer *> API::getOffers(Seller *seller)
{
    return productRepository->getOffers(seller);
}

Offer *API::getOffer(int offerId)
{
    return productRepository->getOffer(offerId);
}

vector<Offer *> API::getOffers()
{
    return productRepository->getOffers();
}