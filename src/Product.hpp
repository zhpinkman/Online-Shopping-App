#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <string>
#include <vector>

class Comment;
class User;
class Seller;
class Offer;

class Product
{
public:
    Product(int _id, std::string _name);
    // virtual bool operator<(const Product &p) = 0;
    virtual std::string getProductInfo() = 0;
    int getId();
    std::string getName();
    bool productIdMatches(int productId);
    std::vector<User *> getProductSellers();
    void addComment(User *user, std::string comment);
    void addRate(User *user, int rate);
    int getOverallRating();
    std::vector<Offer *> sortOffersBy(std::string info);
    void addOffer(Offer *offer);
    Offer* getOffer(Seller* seller);
    Offer* getOffer(int offerId);
    std::vector<Offer*> getOffers();
    static bool compareById(Product* first, Product* second);
    std::vector< Comment* > getComments();

protected:
    std::string name;

private:
    int id;
    std::vector<Offer*> offers;
    std::vector<Comment*> comments;
    std::vector< std::pair<User*, int> > rates;
};

#endif
