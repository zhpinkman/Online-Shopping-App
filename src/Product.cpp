#include "Product.hpp"
using namespace std;

Product::Product() {}
bool Product::operator<(const Product &p) {}
void Product::getProductInfo() {}
int Product::getId() {}
std::string Product::getName() {}
bool Product::productNameMatches(std::string productName) {}
std::vector<User *> Product::getProductSellers() {}
void Product::addComment(User *user, std::string comment) {}
void Product::addRate(User *user, int rate) {}
int Product::getOverallRating() {}
std::vector<Offer *> Product::sortOffersBy(std::string info) {}
void Product::addOffer(Offer *offer) {}