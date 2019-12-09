#include <iostream>
#include <vector>
#include <string>
#include "Interface.hpp"
#include "Exception.hpp"
#include "Exceptions.hpp"
#include "constants.hpp"
#include "Tools.hpp"

using namespace std;

void Interface::start()
{
    processCommands();
}

void Interface::processCommands()
{
    string command;

    while(getline(cin, command))
        processCommand(command);
}

void Interface::processCommand(string command)
{
    try
	{
        vector<string> commandWords = Tools::splitByChar(command, SPACE);
		validateCommand(commandWords);
        runCommand(commandWords);
        printSuccess();
	}		
	catch(const exception &e)
	{
		cerr << e.what() << '\n';
	}
}

void Interface::validateCommand(const vector<string> &commandWords)
{
    validateCommandSize(commandWords);
    validateCommandType(commandWords);
    validateCommandOrder(commandWords);
}

void Interface::validateCommandSize(const vector<string> &commandWords)
{
    if(commandWords.size() < MIN_COMMAND_SIZE)
        throw Bad_Request_Exception();
}

void Interface::validateCommandType(const vector<string> &commandWords)
{
    if(commandWords[0] != POST && commandWords[0] != GET)
        throw Not_Found_Exception();
}

void Interface::validateCommandOrder(const vector<string> &commandWords)
{
    //TODO
}


void Interface::printSuccess()
{
    cout << OK << '\n';
}

void Interface::runCommand(const vector<string> &commandWords)
{
    string order = commandWords[1];

    if(order == SIGNUP)
        runSignupCommand(commandWords);
    else if(order == LOGIN)
        runLoginCommand(commandWords);
    else if(order == LOGOUT)
        runLogoutCommand(commandWords);
    else if(order == IMPORT_PRODUCT)
        runImportProductCommand(commandWords);
    else if(order == GET_PRODUCTS)
        runGetProductsCommand(commandWords);
    else if(order == OFFER)
        runOfferCommand(commandWords);
    else if(order == MY_OFFERS)
        runMyOffersCommand(commandWords);
    else if(order == CHANGE_OFFER)
        runChangeOfferCommand(commandWords);
    else if(order == OFFERS)
        runOffersCommand(commandWords);
    else if(order == OFFERS_ON_PRODUCT)
        runOffersOnProductCommand(commandWords);
    else if(order == PRODUCT_DETAIL)
        runProductDetailCommand(commandWords);
    else if(order == COMMENTS)
        runCommentsCommand(commandWords);
    else if(order == ADD_TO_CART)
        runAddToCartCommand(commandWords);
    else if(order == GENERATE_DISCOUNT_CODE)
        runGenerateDiscountCode(commandWords);
    else if(order == WALLET)
        runWalletCommand(commandWords);
    else
        throw Not_Found_Exception();
}

void Interface::runSignupCommand(const vector<string> &commandWords)
{
    string email = commandWords[4];
    string username = commandWords[6];
    string password = commandWords[8];
    UserType userType = BUYER;

    if(commandWords.size() == SIGNUP_MAX_SIZE)
        userType = (commandWords[10] == BUYER_STR ? BUYER : SELLER);
    
    jomeBazaar.signup(email, username, password, userType);
}


void Interface::runLoginCommand(const vector<string> &commandWords)
{
    string email = commandWords[4];
    string password = commandWords[6];

    jomeBazaar.login(email, password);
}

void Interface::runLogoutCommand(const std::vector<std::string> &commandWords)
{
    jomeBazaar.logout();
}

void Interface::runImportProductCommand(const std::vector<std::string> &commandWords)
{
    string type = commandWords[4];
    string filePath = commandWords[6];

    jomeBazaar.importProduct(type, filePath);
}

void Interface::runGetProductsCommand(const std::vector<std::string> &commandWords)
{
    jomeBazaar.getProducts();
}

void Interface::runOfferCommand(const std::vector<std::string> &commandWords)
{
    int productId = stoi(commandWords[4]);
    double offerUnitPrice = stod(commandWords[6]);
    int offerAmount = stoi(commandWords[8]);

    jomeBazaar.offer(productId, offerUnitPrice, offerAmount);
}

void Interface::runMyOffersCommand(const std::vector<std::string> &commandWords)
{
    jomeBazaar.myOffers();
}

void Interface::runChangeOfferCommand(const std::vector<std::string> &commandWords)
{
    int offerId = stoi(commandWords[4]);
    double offerUnitPrice = stod(commandWords[6]);
    int offerAmount = stoi(commandWords[8]);

    jomeBazaar.changeOffer(offerId, offerUnitPrice, offerAmount);
}

void Interface::runOffersCommand(const std::vector<std::string> &commandWords)
{
    string order = commandWords[4];
    string field = commandWords[6];

    jomeBazaar.offers(order, field);
}

void Interface::runOffersOnProductCommand(const std::vector<std::string> &commandWords)
{
    int productId = stoi(commandWords[4]);

    jomeBazaar.offersOnProduct(productId);
}

void Interface::runProductDetailCommand(const std::vector<std::string> &commandWords)
{
    int productId = stoi(commandWords[4]);

    jomeBazaar.productDetail(productId);
}

void Interface::runCommentsCommand(const std::vector<std::string> &commandWords)
{
    int productId = stoi(commandWords[4]);

    jomeBazaar.comments(productId);
}

void Interface::runAddToCartCommand(const std::vector<std::string> &commandWords)
{
    int offerId = stoi(commandWords[4]);
    int amount = stoi(commandWords[6]);
    string discountCode = (commandWords.size() == ADD_TO_CARD_MAX_SIZE ? commandWords[8] : "");

    jomeBazaar.addToCart(offerId, amount, discountCode);
}

void Interface::runGenerateDiscountCode(const std::vector<std::string> &commandWords)
{
    int offerId = stoi(commandWords[4]);
    int discountPercent = stoi(commandWords[6]);
    int discountNumber = stoi(commandWords[8]);

    jomeBazaar.generateDiscountCard(offerId, discountPercent, discountNumber);
}

void Interface::runWalletCommand(const std::vector<std::string> &commandWords)
{
    int count = stoi(commandWords[4]);
    jomeBazaar.wallet(count);
}