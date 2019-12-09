#ifndef _WALLET_H_
#define _WALLET_H_

#include <string>
#include <vector>

class Wallet
{
public:
    Wallet(int id);
    std::vector<double> getHistory(int bound);
    void charge(double amount);
    bool withdraw(double amount);
    
private:
    int id;
    double balance;
    std::vector<double> history;
};

#endif