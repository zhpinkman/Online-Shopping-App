#include "API.hpp"
#include "UserRepository.hpp"
#include "ProductRepository.hpp"

API::API(UserRepository *_userRepository, ProductRepository *_productRepository)
{
    userRepository = _userRepository;
    productRepository = _productRepository;
}

int API::getOfferId()
{
    return productRepository->getNextOfferId();
}

bool API::isValidDiscountCode(std::string code)
{
    return productRepository->isDiscountCodeUnique(code);
}

int API::useDiscountCode(std::string discountCode)
{
    return productRepository->useDiscountCode(discountCode);
}

bool API::isValidDiscountCode(Offer *offer, std::string code)
{
    return productRepository->isDiscountCodeValid(offer, code);
}

bool API::canBeAddedToCart(Offer *offer, int amount)
{
    return productRepository->canBeAddedToCart(offer, amount);
}
