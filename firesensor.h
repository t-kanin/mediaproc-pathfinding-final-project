#ifndef FIRESENSOR_H
#define FIRESENSOR_H

#include <iostream>
#include <string.h>
#include <memory>
#include <vector>

#include "sensor.h"

class FireSensor : public Sensor
{
public:
    FireSensor(const std::string & vendor, float sensitivity);
    float getSensitivity() const;
    void setSensitivity(float sensitivity);
    std::string trigger() const override;
    std::string getInfo() const override;

private:
    float sensitivity;
};

#endif // FIRESENSOR_H
