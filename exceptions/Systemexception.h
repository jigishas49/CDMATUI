#ifndef SYSTEMEXCEPTION_H
#define SYSTEMEXCEPTION_H

#include <iostream>
#include <sstream>

using namespace std;

class SystemException : public std::exception
{
    string message;
public:
    SystemException();
    SystemException(string Message, string File, int Line);
    // exception interface
public:
    virtual const char *what() const noexcept override;
};

#endif // SYSTEMEXCEPTION_H
