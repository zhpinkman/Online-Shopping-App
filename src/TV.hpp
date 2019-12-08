#ifndef _USER_H_
#define _USER_H_

#include "Product.hpp"
#include <string>

class Tv : public Product
{
public:
    Tv();
    bool operator<(const Tv &t);
    void getProductInfo();

private:
    int displaySize;
    std::string displayType;
    std::string quality;
    bool _3D;
    bool HDR;
};

#endif
