#include "user.hpp"
#include <vector>

class UserRepository
{
private:
    std::vector<User *> users;

public:
    UserRepository();
    User *getUser(std::string username);
    UserRepository *getInstance();
};
