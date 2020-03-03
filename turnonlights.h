#ifndef TURNONLIGHTS_H
#define TURNONLIGHTS_H

#include "alarm.h"

class TurnOnLights : public Alarm
{
public:
    TurnOnLights();
    std::string trigger() const override;
    std::string getInfo() const override;
};

#endif // TURNONLIGHTS_H
