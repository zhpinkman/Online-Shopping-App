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
    if(commandWords[0] != POST || commandWords[0] != GET)
        throw Not_Found_Exception();
}

void Interface::validateCommandOrder(const vector<string> &commandWords)
{
    //TODO
}