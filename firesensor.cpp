#include "firesensor.h"

FireSensor::FireSensor(const std::string &vendor, float sensitivity)
    : Sensor(vendor), sensitivity{sensitivity}
{
    type = "FIRE";
}

float FireSensor::getSensitivity() const
{
    return sensitivity;
}

void FireSensor::setSensitivity(float sensitivity)
{
    this->sensitivity = sensitivity;
}

std::string FireSensor::trigger() const
{
    std::stringstream result;
    result << "[ALERT!] Fire Sensor ";
    result << Sensor::trigger();
    return result.str();
}

std::string FireSensor::getInfo() const
{
    std::stringstream result;
    result << "Fire Sensor ID: " << getID() << std::endl;
    result << "Sensitivity: " << getSensitivity() << std::endl;
    result << Sensor::getInfo();
    return result.str();
}
