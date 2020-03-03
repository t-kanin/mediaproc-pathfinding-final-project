#ifndef CALLPOLICE_H
#define CALLPOLICE_H

#include "alarm.h"

class CallPolice : public Alarm
{
public:
    CallPolice();
    std::string trigger() const override;
    std::string getInfo() const override;
};

#endif // CALLPOLICE_H
