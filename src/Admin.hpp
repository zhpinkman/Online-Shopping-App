#ifndef _ADMIN_H_
#define _ADMIN_H_

#include "User.hpp"
#include "API.hpp"

class Admin : public User
{
public:
    Admin(API* _api);
    void importProductsFromCSV(std::string type, std::string filePath);
    void addComment(std::string productName, std::string comment);
    void importCommentsFromCSV(std::string fileName);
    bool checkAuthorization(std::string endpointID);
    void printAllOffers(std::string order, std::string field);
};

#endif
