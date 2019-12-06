#include "offer.hpp"

#include <string>
#include <vector>

class User;

class Product
{
private:
    int id;
    std::string name;
    std::string description;
    std::vector<Offer *> offers;
    std::vector<std::pair<User *, std::string>> comments;
    std::vector<std::pair<User *, int>> rates;

public:
    Product();
    virtual bool operator<(const Product &p) = 0;
    virtual void getProductInfo() = 0;
    int getId();
    std::string getName();
    bool productNameMatches(std::string productName);
    std::vector<User *> getProductSellers();
    void addComment(User *user, std::string comment);
    void addRate(User *user, int rate);
    int getOverallRating();
    std::vector<Offer *> sortOffersBy(std::string info);
    void addOffer(Offer *offer);
};
