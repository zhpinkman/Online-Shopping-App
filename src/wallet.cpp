#include "wallet.hpp"
#include "userRepository.hpp"
#include "constants.hpp"
#include <iostream>

Wallet::Wallet(int _id)
{
    balance = 0;
    id = _id;
}

std::vector<double> Wallet::getHistory(int bound)
{
    std::vector<double> walletHistory;
    int historyIndex = 0;
    while (historyIndex < bound)
    {
        walletHistory.push_back(history[historyIndex++]);
    }
    return walletHistory;
}

bool Wallet::charge(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        std::cout << OK << std::endl;
        return SUCCESS;
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
        return FAILED;
    }
}

bool Wallet::withdraw(double amount)
{
    if (amount >= balance)
    {
        balance -= amount;
        std::cout << OK << std::endl;
        return SUCCESS;
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
        return FAILED;
    }
}