#include "motionsensor.h"

MotionSensor::MotionSensor(const std::string &vendor, float min, float max)
    : Sensor(vendor), range{std::make_pair(min, max)}
{
    type = "MOTION";
}

std::pair<float,float> MotionSensor:: getRange() const{
    return range;
}

void MotionSensor:: setRange(float min, float max){
    range = std::make_pair(min,max);
}

std::string MotionSensor::trigger() const
{
    std::stringstream result;
    result << "[ALERT!] Motion Sensor ";
    result << Sensor::trigger();
    return result.str();
}

std::string MotionSensor::getInfo() const
{
    std::stringstream result;
    result << "Motion Sensor ID: " << getID() << std::endl;
    result << "Range: " << range.first << " - " << range.second << std::endl;
    result << Sensor::getInfo();
    return result.str();
}
