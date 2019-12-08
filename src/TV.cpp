#include "TV.hpp"
#include "Tools.hpp"
using namespace std;

TV::TV(int _id, const std::vector<std::string> &info) : Product(_id, info[0])
{
    screenSize = stoi(info[1]);
    screenType = info[2];
    resolution = info[3];
    _3D = Tools::stringToBool(info[4]);
    HDR = Tools::stringToBool(info[5]);  
}