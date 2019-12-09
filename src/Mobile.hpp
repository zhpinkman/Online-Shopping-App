#ifndef _MOBILE_H_
#define _MOBILE_H_

#include <vector>
#include <string>
#include "Product.hpp"

class Mobile : public Product
{
public:
    Mobile(int _id, const std::vector<std::string> &info);
    bool operator<(const Mobile &m);
    std::string getProductInfo();

private:
    double weight;
    double cpuFrequency;
    int builtInMemory;
    int ram;
    double displaySize;
    int cameraResolution;
    std::string os;
};

#endif