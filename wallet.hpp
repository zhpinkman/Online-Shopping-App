#include <string>
#include <vector>

class Wallet
{
private:
    std::string id;
    double balance;
    std::vector<double> history;

public:
    Wallet();
    std::vector<double> getHistory(int bound);
    bool charge(double amount);
    bool withdraw(double amount);
};
