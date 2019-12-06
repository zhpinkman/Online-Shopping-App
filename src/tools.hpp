#include <vector>
#include <string>
#include <fstream>

class Tools
{
private:
public:
    Tools();
    std::fstream openCSVFile(std::string fileName);
    std::vector<std::string> parseCSVFile(std::fstream file);
    std::vector<std::string> splitBySpace(std::string spacedString);
    std::string generateRandomString();
};
