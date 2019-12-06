#include <string>

class User
{
private:
    int id;
    std::string username;
    std::string password;
    std::string email;

public:
    User();
    bool checkAuthorization(std::string endpointID);
};