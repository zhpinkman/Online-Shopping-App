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