class UserRepository;
class ProductRepository;

class Api
{

private:
    UserRepository *userRepository;
    ProductRepository *productRepository;

public:
    Api(UserRepository *userRepository, ProductRepository *productRepository);
    bool isValidDiscountCode(std::string code);
    bool isValidDiscountCode(Offer *offer, std::string code);
    int useDiscountCode(std::string discountCode);
    int getOfferId();
    bool canBeAddedToCart(Offer *offer, int amount);
};