#ifndef _WALLET_H_
#define _WALLET_H_

#include <string>
#include <vector>

class Wallet
{
private:
    int id;
    double balance;
    std::vector<double> history;

public:
    Wallet(int id);
    std::vector<double> getHistory(int bound);
    bool charge(double amount);
    bool withdraw(double amount);
};

#endif