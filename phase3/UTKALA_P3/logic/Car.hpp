#ifndef _CAR_H_
#define _CAR_H_

#include <vector>
#include <string>
#include "Product.hpp"

class Car : public Product
{
public:
    Car(int _id, const std::vector<std::string> &info);
    bool operator<(const Car &c);
    std::string getProductInfo();
    virtual std::string compare(Product* otherProduct);
    virtual std::string compare(Car* car);

private:
    double weight;
    int seatsNum;
    int cylindersNum;
    int engineCapacity;
    bool rearSensor;
};

#endif
