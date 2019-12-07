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
        vector<string> commandWords = Tools::splitBySpace(command);
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

void Interface::runCommand(const vector<string> &commandWords)
{
    string order = commandWords[1];

    if(order == SIGNUP)
        runSignupCommand(commandWords);
    else if(order == LOGIN)
        runLoginCommand(commandWords);
    else if(order == LOGOUT)
        runLogoutCommand(commandWords);
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

void Interface::printSuccess()
{
    cout << OK << '\n';
}