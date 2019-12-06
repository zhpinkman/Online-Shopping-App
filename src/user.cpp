#include "user.hpp"

User::User(Api *_api, int id, std::string _username, std::string _email, std::string _password)
{
    api = _api;
    username = _username;
    email = _email;
    password = _password;
}
bool User::checkAuthorization(std::string endpointID)
{
    // TODO
}

bool User::passwordMatches(std::string _password)
{
    return password == _password;
}

bool User::emailMatches(std::string _email)
{
    return email == _email;
}