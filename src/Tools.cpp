#include "Tools.hpp"
#include <sstream>
#include <fstream>
#include <random>
#include <algorithm>
using namespace std;

Tools::Tools()
{
}
vector<string> Tools::splitBySpace(string spacedString)
{
    vector<string> words;
    istringstream wordsStream(spacedString);

    string word;
    while (wordsStream >> word)
        words.push_back(word);

    return words;
}

std::fstream Tools::openCSVFile(std::string fileName) {}
std::vector<std::string> Tools::parseCSVFile(std::fstream file) {}
std::string Tools::generateRandomString()
{

    std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
    std::random_device rd;
    std::mt19937 generator(rd());

    std::shuffle(str.begin(), str.end(), generator);

    return str.substr(0, 32); // assumes 32 < number of characters in str
}