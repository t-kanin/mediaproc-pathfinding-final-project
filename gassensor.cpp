#include "gassensor.h"

GasSensor::GasSensor(const std::string &vendor, const std::string &gasType, float threshold)
    : Sensor(vendor), gasType{gasType}, threshold{threshold}
{
    type = "GAS";
}

const std::string GasSensor::getGasType() const
{
    return gasType;
}

float GasSensor::getThreshold() const
{
    return threshold;
}

void GasSensor:: setThreshold(float threshold)
{
    this->threshold = threshold;
}

std::string GasSensor:: trigger() const
{
    std::stringstream result;
    result << "[ALERT!] Gas Sensor ";
    result << Sensor::trigger();
    return result.str();
}

std::string GasSensor::getInfo() const
{
    std::stringstream result;
    result << "Gas Sensor ID: " << getID() << std::endl;
    result << "Gas Type: " << getGasType() << std::endl;
    result << "Gas Threshold: " << getThreshold() << std::endl;
    result << Sensor::getInfo();
    return result.str();
}
