#include "tools.hpp"
#include <random>
#include <algorithm>

Tools::Tools()
{
}

std::fstream Tools::openCSVFile(std::string fileName) {}
std::vector<std::string> Tools::parseCSVFile(std::fstream file) {}
std::vector<std::string> Tools::splitBySpace(std::string spacedString) {}
std::string Tools::generateRandomString()
{

    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 32); // assumes 32 < number of characters in str
}