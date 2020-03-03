#include "evacuate.h"

Evacuate::Evacuate() {}

std::string Evacuate::trigger() const
{
    std::stringstream result;
    result << "Evacuating..." << std::endl;
    return result.str();
}

std::string Evacuate::getInfo() const
{
    std::stringstream result;
    result << "Evacuate, ";
    return result.str();
}
