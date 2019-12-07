#include "Admin.hpp"
#include "constants.hpp"

Admin::Admin(API* _api) : User(_api, USER_ID_BEGIN, ADMIN_USERNAME, ADMIN_EMAIL, ADMIN_PASSWORD) {}