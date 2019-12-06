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
    int useDiscountCode(std::string discountCode);
    int getOfferId();
};