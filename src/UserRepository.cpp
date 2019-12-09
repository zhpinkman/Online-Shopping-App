#include "UserRepository.hpp"
#include "constants.hpp"
using namespace std;

UserRepository::UserRepository()
{
    maxUserId = USER_ID_BEGIN;
}

void UserRepository::addUser(User *newUser)
{
    users.push_back(newUser);
}

User *UserRepository::getUser(string email)
{
    for (User* user : users)
    {
        if (user->emailMatches(email))
        {
            return user;
        }
    }
    return nullptr;
}

int UserRepository::getNextUserId()
{
    return ++maxUserId;
}

int UserRepository::getNextWalletId()
{
    return ++maxWalletId;
}