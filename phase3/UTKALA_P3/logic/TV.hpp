#ifndef _TV_H_
#define _TV_H_

#include <vector>
#include <string>
#include "Product.hpp"

class TV : public Product
{
public:
    TV(int _id, const std::vector<std::string> &info);
    bool operator<(const TV &t);
    std::string getProductInfo();
    virtual std::string compare(Product* otherProduct);
    virtual std::string compare(TV* tv);

private:
    int screenSize;
    std::string screenType;
    std::string resolution;
    bool _3D;
    bool HDR;
};

#endif
