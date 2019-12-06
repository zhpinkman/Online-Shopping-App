#include "api.hpp"
#include "productRepository.hpp"

Api::Api(UserRepository *_userRepository, ProductRepository *_productRepository)
{
    userRepository = _userRepository;
    productRepository = _productRepository;
}

int Api::getOfferId()
{
    return productRepository->getNextOfferId();
}

bool Api::isValidDiscountCode(std::string code)
{
    return productRepository->isDiscountCodeUnique(code);
}

int Api::useDiscountCode(std::string discountCode)
{
    return productRepository->useDiscountCode(discountCode);
}

bool Api::isValidDiscountCode(Offer *offer, std::string code)
{
    return productRepository->isDiscountCodeValid(offer, code);
}

bool Api::canBeAddedToCart(Offer *offer, int amount)
{
    return productRepository->canBeAddedToCart(offer, amount);
}
