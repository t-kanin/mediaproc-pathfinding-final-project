#include "callfirebrigade.h"

CallFireBrigade::CallFireBrigade() {}

std::string CallFireBrigade::trigger() const
{
    std::stringstream result;
    result << "Calling fire brigade..." << std::endl;
    return result.str();
}

std::string CallFireBrigade::getInfo() const
{
    std::stringstream result;
    result << "Call Fire Brigade, ";
    return result.str();
}
