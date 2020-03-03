#ifndef ALARM_H
#define ALARM_H

#include <sstream>

class Alarm
{
public:
    Alarm();
    virtual ~Alarm();
    virtual std::string trigger() const = 0;
    virtual std::string getInfo() const = 0;
};

#endif // ALARM_H
