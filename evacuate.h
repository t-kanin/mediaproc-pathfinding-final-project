#ifndef EVACUATE_H
#define EVACUATE_H

#include "alarm.h"

class Evacuate : public Alarm
{
public:
    Evacuate();
    std::string trigger() const override;
    std::string getInfo() const override;
};

#endif // EVACUATE_H
