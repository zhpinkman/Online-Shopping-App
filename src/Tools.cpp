#include "Tools.hpp"
#include <sstream>
using namespace std;

vector<string> Tools::splitBySpace(string spacedString)
{
    vector<string> words;
    istringstream wordsStream(spacedString);

    string word;
    while(wordsStream >> word)
        words.push_back(word);

    return words;
}