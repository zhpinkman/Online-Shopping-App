#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__

#include <string>
#include <exception>

class Exception : public std::exception
{
public:
	Exception(const std::string _msg) : msg(_msg) {}
	virtual ~Exception() throw() {}

	virtual const char *what() const throw()
	{
		return msg.c_str();
	}

private:
	std::string msg;
};

#endif