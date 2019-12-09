#include <sstream>
#include "Mobile.hpp"
using namespace std;

Mobile::Mobile(int _id, const std::vector<std::string> &info) : Product(_id, info[0])
{
    weight = stod(info[1]);
    cpuFrequency = stod(info[2]);
    builtInMemory = stoi(info[3]);
    ram = stoi(info[4]);
    displaySize = stod(info[5]);
    cameraResolution = stod(info[6]);
    string os = info[7];
}

string Mobile::getProductInfo()
{
    ostringstream infoStream;
    
    infoStream << name << '\n';
    infoStream << weight << '\n';
    infoStream << cpuFrequency << '\n';
    infoStream << builtInMemory << '\n';
    infoStream << ram << '\n';
    infoStream << displaySize << '\n';
    infoStream << cameraResolution << '\n';
    infoStream << os;

    return infoStream.str();
}