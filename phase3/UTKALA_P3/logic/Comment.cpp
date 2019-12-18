#include "Comment.hpp"
using namespace std;

Comment::Comment(User* _user, string _text)
{
    user = _user;
    text = _text;
}

User* Comment::getUser()
{
    return user;
}

string Comment::getText()
{
    return text;
}