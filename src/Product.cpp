#include "Product.hpp"
using namespace std;

Product::Product(int _id, std::string _name) : id(_id), name(_name) {}

// bool Product::operator<(const Product &p) {}
// void Product::getProductInfo() {}
int Product::getId()
{
    return id;
}

std::string Product::getName()
{
    return name;
}


bool Product::productNameMatches(std::string productName) {}
std::vector<User *> Product::getProductSellers() {}
void Product::addComment(User *user, std::string comment) {}
void Product::addRate(User *user, int rate) {}
int Product::getOverallRating() {}
std::vector<Offer *> Product::sortOffersBy(std::string info) {}
void Product::addOffer(Offer *offer) {}