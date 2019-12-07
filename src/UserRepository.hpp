#ifndef _USER_REPOSITORY_H_
#define _USER_REPOSITORY_H_

#include <vector>
#include "User.hpp"

class UserRepository
{
public:
    UserRepository();
    void addUser(User *newUser);
    User *getUser(std::string email);
    int getNextUserId();
    int getNextWalletId();

private:
    std::vector<User*> users;
    int maxUserId;
    int maxWalletId;
};

#endif
