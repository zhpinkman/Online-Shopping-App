#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <string>
#include <vector>
#include "JomeBazaar.hpp"

class Interface
{
public:
    void start();

private:
    JomeBazaar jomeBazaar;
    void printSuccess();
    void processCommands();
    void processCommand(std::string command);
    void validateCommand(const std::vector<std::string> &commandWords);
    void validateCommandSize(const std::vector<std::string> &commandWords);
    void validateCommandType(const std::vector<std::string> &commandWords);
    void validateCommandOrder(const std::vector<std::string> &commandWords);
    void runCommand(const std::vector<std::string> &commandWords);
    void runSignupCommand(const std::vector<std::string> &commandWords);
    void runLoginCommand(const std::vector<std::string> &commandWords);
    void runLogoutCommand(const std::vector<std::string> &commandWords);
    void runImportProductCommand(const std::vector<std::string> &commandWords);
    void runGetProductsCommand(const std::vector<std::string> &commandWords);
    void runOfferCommand(const std::vector<std::string> &commandWords);
    void runMyOffersCommand(const std::vector<std::string> &commandWords);
    void runChangeOfferCommand(const std::vector<std::string> &commandWords);
    void runOffersCommand(const std::vector<std::string> &commandWords);
    void runOffersOnProductCommand(const std::vector<std::string> &commandWords);
    void runProductDetailCommand(const std::vector<std::string> &commandWords);
    void runCommentsCommand(const std::vector<std::string> &commandWords);
    void runAddToCartCommand(const std::vector<std::string> &commandWords);
    void runGenerateDiscountCode(const std::vector<std::string> &commandWords);
    void runWalletCommand(const std::vector<std::string> &commandWords);
    void runCartCommand(const std::vector<std::string> &commandWords);
    void runChargeWalletCommand(const std::vector<std::string> &commandWords);
    void runCommentCommand(const std::vector<std::string> &commandWords);
    void runCompareCommand(const std::vector<std::string> &commandWords);
};

#endif