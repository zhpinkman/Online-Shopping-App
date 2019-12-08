#include <iostream>
#include "Wallet.hpp"
#include "constants.hpp"

Wallet::Wallet(int _id)
{
    balance = 0;
    id = _id;
}

std::vector<double> Wallet::getHistory(int bound)
{
    std::vector<double> walletHistory;
    int historyIndex = 0;
    for (int i = 0; i < bound && i < history.size(); i++)
    {
        walletHistory.push_back(history[history.size() - 1 - i]);
    }
    return walletHistory;
}

bool Wallet::charge(double amount)
{
    if (amount > 0)
    {
        balance += amount;
        history.push_back(balance);
        std::cout
            << OK << std::endl;
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
        history.push_back(balance);
        std::cout << OK << std::endl;
        return SUCCESS;
    }
    else
    {
        std::cout << BAD_REQUEST << std::endl;
        return FAILED;
    }
}