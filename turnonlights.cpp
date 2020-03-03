#include "turnonlights.h"

TurnOnLights::TurnOnLights() {}

std::string TurnOnLights::trigger() const
{
    std::stringstream result;
    result << "Turning on lights..." << std::endl;
    return result.str();
}

std::string TurnOnLights::getInfo() const
{
    std::stringstream result;
    result << "Turn on lights, ";
    return result.str();
}
