#include <sstream>
#include "Car.hpp"
#include "Tools.hpp"
#include "constants.hpp"
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

string Car::compare(Product* otherProduct)
{
    return otherProduct->compare(this);
}

string Car::compare(Car* car)
{
    ostringstream result;

    result << car->name << OUTPUT_SEPARATOR << name << '\n';
    result << car->weight << OUTPUT_SEPARATOR << weight << '\n';
    result << car->seatsNum << OUTPUT_SEPARATOR << seatsNum << '\n';
    result << car->cylindersNum << OUTPUT_SEPARATOR << cylindersNum << '\n';
    result << car->engineCapacity << OUTPUT_SEPARATOR << engineCapacity << '\n';
    result << car->rearSensor << OUTPUT_SEPARATOR << rearSensor;

    return result.str();
}