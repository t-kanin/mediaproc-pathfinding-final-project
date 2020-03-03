#ifndef SENSOR_H
#define SENSOR_H

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

#include "alarm.h"
#include "component.h"

class Sensor : public Component
{
public:
    Sensor(const std::string & vendor);
    virtual ~Sensor() override;
    bool addAlarm(std::shared_ptr<Alarm>);
    bool removeAlarm(std::shared_ptr<Alarm>);
    bool getStatus() const;
    bool setStatus(bool activate);
    std::string getType() const;
    std::string getVendor() const;
    std::string trigger() const override;
    std::string getInfo() const override;
    void operator ++ () override;
    void operator -- () override;

private:
    bool status;
    const std::string vendor;
    std::vector<std::shared_ptr<Alarm>> alarms;

protected:
    std::string type;
};



#endif // SENSOR_H
