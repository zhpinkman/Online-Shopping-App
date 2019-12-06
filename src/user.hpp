#include <string>

class User
{
private:
    int id;
    std::string username;
    std::string password;
    std::string email;

public:
    User(int id, std::string username, std::string email, std::string password);
    bool emailMatches(std::string email);
    bool passwordMatches(std::string password);
    bool checkAuthorization(std::string endpointID);
};