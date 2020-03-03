#include "callpolice.h"

CallPolice::CallPolice() {}

std::string CallPolice::trigger() const
{
    std::stringstream result;
    result << "Calling police..." << std::endl;
    return result.str();
}

std::string CallPolice::getInfo() const
{
    std::stringstream result;
    result << "Call Police, ";
    return result.str();
}
