#include "Systemexception.h"

SystemException::SystemException()
{
    message = "Encountered exception";
}

SystemException::SystemException(string Message, string File, int Line)
{
    ostringstream MessageStream;
    MessageStream << "Encountered exception : "<<Message<<" in "<<File<<" at "<<Line;
    message = MessageStream.str();
}

const char *SystemException::what() const noexcept
{
    return message.data();
}
