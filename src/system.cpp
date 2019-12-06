#include "system.hpp"
#include "buyer.hpp"
#include "seller.hpp"
#include "admin.hpp"
#include "constants.hpp"

#include <iostream>

System::System()
{
    userRepository = new UserRepository();
    productRepository = new ProductRepository();
    loggedInUser = nullptr;
}

bool System::signup(std::string email, std::string username, std::string password, UserType userType)
{
    User *newUser;
    User *user = userRepository->getUser(email);
    if (user == nullptr)
    {
        int newUserId = userRepository->getNextUserId();
        int newWalletId = userRepository->getNextWalletId();
        switch (userType)
        {
        case BUYER:
            newUser = new Buyer(newUserId, newWalletId, username, email, password);
            userRepository->addUser(newUser);
            return SUCCESS;
        case SELLER:
            newUser = new Seller(newUserId, newWalletId, username, email, password);
            userRepository->addUser(newUser);
            return SUCCESS;
        default:
            std::cout << BAD_REQUEST << std ::endl;
            return FAILED;
        }
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
        return FAILED;
    }
}
bool System::signin(std::string email, std::string password)
{
    User *user = userRepository->getUser(email);
    if (user != nullptr)
    {
        if (user->passwordMatches(password))
        {
            loggedInUser = user;
            return SUCCESS;
        }
        else
        {
            std::cout << BAD_REQUEST << std::endl;
            return FAILED;
        }
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
        return FAILED;
    }
}
bool System::logout()
{
    if (loggedInUser != nullptr)
    {
        loggedInUser = nullptr;
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
    }
}