#include <sstream>
#include "Car.hpp"
#include "Tools.hpp"
using namespace std;

Car::Car(int _id, const std::vector<std::string> &info) : Product(_id, info[0])
{
    weight = stod(info[1]);
    seatsNum = stoi(info[2]);
    cylindersNum = stoi(info[3]);
    engineCapacity = stoi(info[4]);
    rearSensor = Tools::stringToBool(info[5]);
}

string Car::getProductInfo()
{
    ostringstream infoStream;

    infoStream << name << '\n';
    infoStream << weight << '\n';
    infoStream << seatsNum << '\n';
    infoStream << cylindersNum << '\n';
    infoStream << engineCapacity << '\n';
    infoStream << rearSensor;
    
    return infoStream.str();
}