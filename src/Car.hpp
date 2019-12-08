#ifndef _CAR_H_
#define _CAR_H_

#include <string>
#include "Product.hpp"

class Car : public Product
{
public:
    Car();
    bool operator<(const Car &c);
    void getProductInfo();

private:
    enum type : int;
    int capacity;
    int cylinderNum;
    int weight;
    int motorCapacity;
    bool rearSensor;
};

#endif
