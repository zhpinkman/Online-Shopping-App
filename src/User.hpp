#ifndef _USER_H_
#define _USER_H_

#include <string>
#include "API.hpp"

class User
{
public:
    User(API* _api, int _id, std::string _username, std::string _email, std::string _password);
    int getId();
    bool emailMatches(std::string email);
    bool passwordMatches(std::string password);
    bool checkAuthorization(std::string endpointID);

private:
    int id;
    std::string username;
    std::string password;
    std::string email;

protected:
    API* api;
};

#endif