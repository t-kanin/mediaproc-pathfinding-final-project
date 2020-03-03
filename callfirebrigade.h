#ifndef CALLFIREBRIGADE_H
#define CALLFIREBRIGADE_H

#include "alarm.h"

class CallFireBrigade : public Alarm
{
public:
    CallFireBrigade();
    std::string trigger() const override;
    std::string getInfo() const override;
};

#endif // CALLFIREBRIGADE_H
