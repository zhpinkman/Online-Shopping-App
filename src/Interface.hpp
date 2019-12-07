#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include <string>
#include <vector>

class Interface
{
public:
    void start();

private:
    void processCommands();
    void processCommand(std::string command);
    void validateCommand(const std::vector<std::string> &commandWords);
    void validateCommandSize(const std::vector<std::string> &commandWords);
    void validateCommandType(const std::vector<std::string> &commandWords);
    void validateCommandOrder(const std::vector<std::string> &commandWords);
};

#endif