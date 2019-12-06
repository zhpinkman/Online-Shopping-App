#include "user.hpp"
#include "wallet.hpp"
#include "offer.hpp"
#include "factor.hpp"

class CartItem;

class Buyer : public User
{
private:
    Wallet *wallet;
    std::vector<CartItem *> cart;

public:
    Buyer(int userId, int walletId, std::string username, std::string email, std::string password);
    bool addToCart(Offer *offer, int amout, std::string discountCode);
    bool submitCart();
    std::vector<std::string> getOrdersHistory(int bound);
    std::vector<std::string> getTransactionHistory(int bound);
    bool chargeWallet(double amount);
    std::vector<std::string> getCoupons();
    bool payFactor(Factor *factor);
    bool checkAuthorization(std::string endpointID);
};