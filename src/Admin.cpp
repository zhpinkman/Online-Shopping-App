#include <fstream>
#include <vector>
#include "Admin.hpp"
#include "Tools.hpp"
#include "constants.hpp"

using namespace std;

Admin::Admin(API* _api) : User(_api, USER_ID_BEGIN, ADMIN_USERNAME, ADMIN_EMAIL, ADMIN_PASSWORD) {}

void Admin::importProductsFromCSV(std::string type, std::string filePath)
{
    ifstream file = Tools::openCSVFile(filePath);
    vector< vector<string> > products = Tools::parseCSVFile(file);
    file.close();

    for(int i = 1; i < products.size(); i++)
        api->addProduct(type, products[i]);
}