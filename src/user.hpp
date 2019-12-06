#include <string>
#include "api.hpp"

class Tools;
class System;
class User
{
private:
    int id;
    std::string username;
    std::string password;
    std::string email;

protected:
    Api *api;
    Tools *tools;

public:
    User(Api *api, Tools *tools, int id, std::string username, std::string email, std::string password);
    bool emailMatches(std::string email);
    bool passwordMatches(std::string password);
    bool checkAuthorization(std::string endpointID);
};