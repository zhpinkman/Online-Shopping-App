#include "product.hpp"
#include <string>

class Tv : public Product
{
private:
    int displaySize;
    std::string displayType;
    std::string quality;
    bool _3D;
    bool HDR;

public:
    Tv();
    bool operator<(const Tv &t);
    void getProductInfo();
};
