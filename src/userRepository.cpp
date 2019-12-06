#include "userRepository.hpp"

UserRepository::UserRepository()
{
    maxUserId = 1;
}

void UserRepository::addUser(User *newUser)
{
    users.push_back(newUser);
}

User *UserRepository::getUser(std::string email)
{
    for (User *user : users)
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
    return maxUserId++;
}

int UserRepository::getNextWalletId()
{
    return maxWalletId++;
}