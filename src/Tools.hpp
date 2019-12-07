#ifndef _TOOLS_H_
#define _TOOLS_H_

#include <vector>
#include <string>
#include "constants.hpp"

class Tools
{
public:
    static std::vector<std::string> splitBySpace(std::string spacedString);
};

#endif
