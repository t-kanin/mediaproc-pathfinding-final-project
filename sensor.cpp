#include "sensor.h"

Sensor::Sensor(const std::string& vendor) : vendor{vendor} {}

Sensor::~Sensor() {}

bool Sensor::addAlarm(std::shared_ptr<Alarm> newAlarm)
{
    bool add{true};
    for (auto & alarm : alarms)
    {
        if (alarm == newAlarm) add = false;
    }
    if (add) alarms.push_back(newAlarm);
    return add;
}

bool Sensor::removeAlarm(std::shared_ptr<Alarm> removeAlarm)
{
    bool remove{false};
    auto ltr = std::find(alarms.begin(), alarms.end(), removeAlarm);
    if(ltr != alarms.end())
    {
        alarms.erase(ltr);
        remove = true;
    }
    return remove;
}

bool Sensor::getStatus() const
{
    return status;
}

std::string Sensor::getType() const
{
    return type;
}

std::string Sensor::getVendor() const
{
    return vendor;
}

bool Sensor::setStatus(bool activate)
{
    return status = activate;
}

std::string Sensor::trigger() const
{
     std::stringstream result;
     result << getID() << " is " << std::endl;
     if (!status)
     {
         result << "Deactivated" << std::endl;
     }
     else if (alarms.empty())
     {
         result << "Doing nothing (please set some alarms)" << std::endl;
     }
     else
     {
         for(auto & alarm : alarms)
         {
            result << alarm->trigger();
         }
     }
     result << "---------------------------------------" << std::endl;
     return result.str();
}

std::string Sensor::getInfo() const
{
    std::stringstream result;
    result << "Vendor: " << getVendor() << std::endl;
    result << "Status: " << getStatus() << std::endl;
    result << "List of alarms: ";
    if (alarms.empty())
    {
        result << "None";
    }
    else
    {
        for (auto & alarm : alarms)
        {
            result << alarm->getInfo();
        }
    }
    result << std::endl << "---------------------------------------" << std::endl;
    return result.str();
}

void Sensor::operator ++ ()
{
    setStatus(true);
}

void Sensor::operator -- ()
{
    setStatus(false);
}

