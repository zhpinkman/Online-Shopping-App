#include "user.hpp"
#include <vector>

class UserRepository
{
private:
    std::vector<User *> users;
    int maxUserId;

public:
    UserRepository();
    void addUser(User *newUser);
    User *getUser(std::string email);
    // UserRepository *getInstance();
    int getNextId();
};
