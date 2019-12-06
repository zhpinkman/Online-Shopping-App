#include "product.hpp"
#include <string>

class Car
{
private:
    enum type : int;
    int capacity;
    int cylinderNum;
    int weight;
    int motorCapacity;
    bool rearSensor;

public:
    Car();
    bool operator<(const Car &c);
    void getProductInfo();
};
