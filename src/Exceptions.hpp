#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include "Exception.hpp"

class Not_Found_Exception : public Exception 
{
public:
    Not_Found_Exception() : Exception("Not Found") {}
};

class Bad_Request_Exception : public Exception 
{
public:
    Bad_Request_Exception() : Exception("Bad Request") {}
};

class Permission_Exception : public Exception 
{
public:
    Permission_Exception() : Exception("Permission Denied") {}
};

#endif