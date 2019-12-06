#include "user.hpp"
#include "wallet.hpp"

class Api;

class Seller : public User
{
private:
    Wallet *wallet;

public:
    Seller(Api *api, int userId, int walletId, std::string username, std::string email, std::string password);
    void getTransactionHistory(int bound);
    void generateDiscountCode(Offer *offer, int count, int percentage);
    void addOffer(Product *p, int count, int unitPrice);
    bool checkAuthorization(std::string endpointID);
};
