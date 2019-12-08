#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <vector>
#include <string>
#include "constants.hpp"

class Tools
{
private:
public:
    Tools();
    std::fstream openCSVFile(std::string fileName);
    std::vector<std::string> parseCSVFile(std::fstream file);
    static std::vector<std::string> splitBySpace(std::string spacedString);
    static std::string generateRandomString();
};

#endif
