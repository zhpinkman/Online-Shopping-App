#include "userRepository.hpp"
#include "productRepository.hpp"
#include "constants.hpp"

class System
{
private:
    UserRepository *userRepository;
    ProductRepository *productRepository;
    User *loggedInUser;

public:
    System();
    bool signup(std::string email, std::string username, std::string password, UserType userType);
    bool signin(std::string email, std::string password);
    bool logout();
};
