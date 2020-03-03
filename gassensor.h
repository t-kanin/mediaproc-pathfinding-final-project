#ifndef GASSENSOR_H
#define GASSENSOR_H

#include <iostream>
#include <string.h>
#include <memory>
#include <vector>

#include "sensor.h"

class GasSensor: public Sensor
{
public:
    GasSensor(const std::string & vendor, const std::string & gasType, float threshold);
    float getThreshold() const;
    void setThreshold(float threshold);
    const std::string getGasType() const;
    std::string trigger() const override;
    std::string getInfo() const override;

private:
    const std::string gasType;
    float threshold;
};

#endif // GASSENSOR_H
