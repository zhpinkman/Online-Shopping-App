#include "user.hpp"

class Admin : public User
{
private:
public:
    Admin();
    void addProduct(std::string name, std::string description);
    void importProductsFromCSV(std::string fileName);
    void addComment(std::string productName, std::string comment);
    void importCommentsFromCSV(std::string fileName);
    bool checkAuthorization(std::string endpointID);
};
