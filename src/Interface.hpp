#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <string>

class Interface
{
public:
    void start();

private:
    void processCommands();
    void processCommand(std::string command);
    void validateCommand(std::string command);
    void validateCommandType(std::string command);
    void validateCommandArgs(std::string command);
};

#endif