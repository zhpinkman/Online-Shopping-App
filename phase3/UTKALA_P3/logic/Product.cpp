#include "Product.hpp"
#include "Offer.hpp"
#include "Comment.hpp"
#include "Exceptions.hpp"
using namespace std;

Product::Product(int _id, string _name) : id(_id), name(_name) {}

// bool Product::operator<(const Product &p) {}
int Product::getId()
{
    return id;
}

string Product::getName()
{
    return name;
}

bool Product::productIdMatches(int productId)
{
    return (id == productId);
}

vector<User *> Product::getProductSellers() {

}

void Product::addComment(User *user, string comment)
{
    Comment* newComment = new Comment(user, comment);
    comments.push_back(newComment);
}

void Product::addRate(User *user, int rate) {}
int Product::getOverallRating() {}
vector<Offer *> Product::sortOffersBy(string info) {}

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

vector<Offer*> Product::getOffers()
{
    return offers;
}

bool Product::compareById(Product* first, Product* second)
{
    return first->id < second->id;
}

vector<Comment*> Product::getComments()
{
    return comments;
}

string Product::compare(Product* otherProduct)
{
    throw Bad_Request_Exception();
}

string Product::compare(Mobile* mobile)
{
    throw Bad_Request_Exception();
}

string Product::compare(TV* tv)
{
    throw Bad_Request_Exception();
}

string Product::compare(Car* car)
{
    throw Bad_Request_Exception();
}