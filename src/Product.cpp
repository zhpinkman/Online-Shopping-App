#include "Product.hpp"
#include "Offer.hpp"
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


bool Product::productIdMatches(int productId)
{
    return (id == productId);
}

std::vector<User *> Product::getProductSellers() {}
void Product::addComment(User *user, std::string comment) {}
void Product::addRate(User *user, int rate) {}
int Product::getOverallRating() {}
std::vector<Offer *> Product::sortOffersBy(std::string info) {}

void Product::addOffer(Offer *offer)
{
    offers.push_back(offer);
}

Offer* Product::getOffer(Seller* seller)
{
    for(Offer* offer : offers)
        if(offer->sellerMatches(seller))
            return offer;

    return nullptr;
}

Offer* Product::getOffer(int offerId)
{
    for(Offer* offer : offers)
        if(offer->idMatches(offerId))
            return offer;

    return nullptr;
}