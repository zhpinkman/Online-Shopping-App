#include <string>

class Discount
{
private:
    std::string code;
    enum status : int;
    int percentage;

public:
    Discount();
};
