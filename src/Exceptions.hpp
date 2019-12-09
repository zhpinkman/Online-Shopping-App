#ifndef __EXCEPTIONS_H__
#define __EXCEPTIONS_H__

#include "Exception.hpp"

#define NOT_FOUND "Not Found"
#define BAD_REQUEST "Bad Request"
#define PERMISSION_DENIED "Permission Denied"

class Not_Found_Exception : public Exception
{
public:
    Not_Found_Exception() : Exception(NOT_FOUND) {}
};

class Bad_Request_Exception : public Exception
{
public:
    Bad_Request_Exception() : Exception(BAD_REQUEST) {}
};

class Permission_Exception : public Exception
{
public:
    Permission_Exception() : Exception(PERMISSION_DENIED) {}
};

#endif