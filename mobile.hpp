#include "product.hpp"

class Moblie : public Product
{
private:
    enum color : int;
    int weight;
    int simcardNum;
    int CPU;
    int RAM;

public:
    Moblie();
    bool operator<(const Moblie &m);
    void getProductInfo();
};
