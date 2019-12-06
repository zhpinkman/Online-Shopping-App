#include "user.hpp"
#include "wallet.hpp"

class Seller : public User
{
private:
    Wallet *wallet;

public:
    Seller();
    void getTransactionHistory(int bound);
    void generateDiscountCode(Offer *offer, int count, int percentage);
    void addOffer(Product *p, int amount, int unitPrice);
    bool checkAuthorization(std::string endpointID);
};
