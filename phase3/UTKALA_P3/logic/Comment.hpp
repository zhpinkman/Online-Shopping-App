#ifndef _COMMENT_H_
#define _COMMENT_H_

#include <string>
#include "User.hpp"

class Comment
{
public:
    Comment(User* _user, std::string _text);
    User* getUser();
    std::string getText();

private:
    User* user;
    std::string text;
};

#endif