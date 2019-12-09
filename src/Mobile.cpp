#include <sstream>
#include "Mobile.hpp"
#include "constants.hpp"
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

string Mobile::compare(Product* otherProduct)
{
    return otherProduct->compare(this);
}

string Mobile::compare(Mobile* mobile)
{
    ostringstream result;

    result << mobile->name << OUTPUT_SEPARATOR << name << '\n';
    result << mobile->weight << OUTPUT_SEPARATOR << weight << '\n';
    result << mobile->cpuFrequency << OUTPUT_SEPARATOR << cpuFrequency << '\n';
    result << mobile->ram << OUTPUT_SEPARATOR << ram << '\n';
    result << mobile->displaySize << OUTPUT_SEPARATOR << displaySize << '\n';
    result << mobile->cameraResolution << OUTPUT_SEPARATOR << cameraResolution << '\n';
    result << mobile->os << OUTPUT_SEPARATOR << os;

    return result.str();
}
