#ifndef MOTIONSENSOR_H
#define MOTIONSENSOR_H

#include <iostream>
#include <string.h>
#include <memory>
#include <vector>

#include "sensor.h"

class MotionSensor : public Sensor
{
public:
    MotionSensor(const std::string & vendor, float min, float max);
    std::pair<float,float> getRange() const;
    void setRange(float min, float max);
    std::string trigger() const override;
    std::string getInfo() const override;

private:
    std::pair<float,float> range;
};

#endif // MOTIONSENSOR_H
