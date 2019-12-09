#include <sstream>
#include "TV.hpp"
#include "Tools.hpp"
#include "constants.hpp"
using namespace std;

TV::TV(int _id, const std::vector<std::string> &info) : Product(_id, info[0])
{
    screenSize = stoi(info[1]);
    screenType = info[2];
    resolution = info[3];
    _3D = Tools::stringToBool(info[4]);
    HDR = Tools::stringToBool(info[5]);  
}

string TV::getProductInfo()
{
    ostringstream infoStream;

    infoStream << name << '\n';
    infoStream << screenSize << '\n';
    infoStream << screenType << '\n';
    infoStream << _3D << '\n';
    infoStream << HDR;

    return infoStream.str();
}

string TV::compare(Product* otherProduct)
{
    return otherProduct->compare(this);
}

string TV::compare(TV* tv)
{
    ostringstream result;

    result << tv->name << OUTPUT_SEPARATOR << name << '\n';
    result << tv->screenSize << OUTPUT_SEPARATOR << screenSize << '\n';
    result << tv->screenType << OUTPUT_SEPARATOR << screenType << '\n';
    result << tv->_3D << OUTPUT_SEPARATOR << _3D<< '\n';
    result << tv->HDR << OUTPUT_SEPARATOR << HDR;

    return result.str();
}