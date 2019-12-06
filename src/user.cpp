#include "user.hpp"

User::User(int id, std::string _username, std::string _email, std::string _password)
{
    username = _username;
    email = _email;
    password = _password;
}
bool User::checkAuthorization(std::string endpointID)
{
}

bool User::passwordMatches(std::string _password)
{
    return password == _password;
}