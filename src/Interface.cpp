#include <iostream>
#include <vector>
#include <string>
#include "Interface.hpp"
#include "Exception.hpp"
#include "Exceptions.hpp"

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
		
	}		
	catch(const exception &e)
	{
		cerr << e.what() << '\n';
	}
}

void Interface::validateCommand(string command)
{
    validateCommandType(command);
}

void Interface::validateCommandType(string command)
{

}

void Interface::validateCommandArgs(string command)
{

}