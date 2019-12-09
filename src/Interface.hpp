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
};

#endif