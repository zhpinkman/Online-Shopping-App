#include "user.hpp"
#include <vector>

class UserRepository
{
private:
    std::vector<User *> users;
    int maxUserId;
    int maxWalletId;

public:
    UserRepository();
    void addUser(User *newUser);
    User *getUser(std::string email);
    // UserRepository *getInstance();
    int getNextUserId();
    int getNextWalletId();
};
