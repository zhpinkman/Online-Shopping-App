#include <iostream>
#include <utility>
#include "Buyer.hpp"
#include "CartItem.hpp"
#include "constants.hpp"
#include "PrintTools.hpp"
#include "Exceptions.hpp"
#include "Comment.hpp"
using namespace std;

Buyer::Buyer(API *api, int userId, int walletId, string username, string email, string password) : User(api, userId, username, email, password)
{
    wallet = new Wallet(walletId);
    cart = new Cart();
}

void Buyer::addToCart(int offerId, int amount, string discountCode = "")
{
    Offer *offer = api->getOffer(offerId);

    if (api->isValidDiscountCode(offer, discountCode) || discountCode == "")
    {
        api->checkAvailability(offer, amount);
        int discountPercentage = 0;
        if (discountCode != "")
            discountPercentage = api->useDiscountCode(discountCode);
        CartItem *cartItem = new CartItem(offer, amount, discountPercentage);
        cart->addCartItem(cartItem);
        cout << OK << '\n';
    }
    else
    {
        throw Bad_Request_Exception();
    }
}

void Buyer::submitCart()
{
    Factor *factor = new Factor(cart);
    double finalPrice = factor->getFinalPrice();
    if (wallet->hasEnoughMoney(finalPrice))
    {
        wallet->withdraw(finalPrice);
        orders.push_back(cart);
        cart->addCreditToSellers();
        cart->restartCart();
        cout << OK << '\n';
    }
    else
    {
        throw Bad_Request_Exception();
    }
}
void Buyer::getOrdersHistory(int bound)
{
    for (int i = 0; i < (bound < orders.size() ? bound : orders.size()); i++)
    {
        orders[i]->printCart();
    }
}

vector<string> Buyer::getTransactionHistory(int bound)
{
    vector<double> transactionHistory = wallet->getHistory(bound);
    for (double transaction : transactionHistory)
    {
        cout << transaction << '\n';
    }
}

void Buyer::chargeWallet(double amount)
{
    wallet->charge(amount);
}

void Buyer::printProducts()
{
    api->printProducts();
}

void Buyer::printOffersOnProduct(int productId)
{
    Product *product = api->getProduct(productId);
    vector<Offer *> offers = product->getOffers();

    PrintTools::printOffersInitBuyer();

    for (Offer *offer : offers)
        PrintTools::printOfferInfoBuyer(offer);
}

void Buyer::productDetail(int productId)
{
    Product *product = api->getProduct(productId);
    string productInfo = product->getProductInfo();

    cout << productInfo << '\n';
}

void Buyer::comments(int productId)
{
    Product *product = api->getProduct(productId);
    vector<Comment *> comments = product->getComments();

    cout << product->getName() << '\n';
    for (Comment *comment : comments)
    {
        User *user = comment->getUser();
        string commentMessage = comment->getText();
        cout << user->getUsername() << OUTPUT_SEPARATOR << commentMessage << '\n';
    }
}

void Buyer::showWallet(int count)
{
    cout << CREDIT << '\n';
    vector<double> transactionHistory = wallet->getHistory(count);
    for (double transaction : transactionHistory)
        cout << transaction << '\n';
}

void Buyer::addComment(int productId, string comment)
{
    Product *product = api->getProduct(productId);
    if (product == nullptr)
        throw Not_Found_Exception();

    product->addComment(this, comment);
}

void Buyer::compare(int productId1, int productId2)
{
    Product *product1 = api->getProduct(productId1);
    Product *product2 = api->getProduct(productId2);

    string compareResult = product1->compare(product2);
    cout << compareResult << '\n';
}

void Buyer::logout()
{
    cart->removeCartItems();
}