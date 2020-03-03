/*
 * Pariwat Hongladarom - r0649939
 * Kanin Tansirisittikul - r0649941
 */

#include <iostream>
#include <memory>

#include "group.h"
#include "firesensor.h"
#include "motionsensor.h"
#include "gassensor.h"
#include "callfirebrigade.h"
#include "evacuate.h"
#include "callpolice.h"
#include "turnonlights.h"

/*
 * In reality, instead of sending trigger signal from the emergency center to the sensors, it will be the
 * other way around. In such case, there needs to be a function which receives a sensor input (i.e.
 * gas concentraion from gas sensors). If the concentration is above the threshold, then the sensors
 * will send its trigger signal to the center.
 */

int main()
{
    /* Initialization */

    // components
    auto building1 = std::make_shared<Group>(Entity::Building);
    auto level1 = std::make_shared<Group>(Entity::Level);
    auto level2 =std::make_shared<Group>(Entity::Level);
    auto room1 = std::make_shared<Group>(Entity::Room);
    auto room2 = std::make_shared<Group>(Entity::Room);
    auto room3 = std::make_shared<Group>(Entity::Room);
    auto sensor1 = std::make_shared<FireSensor>("Groep T", 20.0f);
    auto sensor2 = std::make_shared<MotionSensor>("Groep T",10,20);
    auto sensor3 = std::make_shared<GasSensor>("KU Leuven","CO2",15.0f);
    auto sensor4 = std::make_shared<FireSensor>("Groep T", 25.0f);
    auto sensor5 = std::make_shared<FireSensor>("KU Leuven",30.0f);
    auto sensor6 = std::make_shared<MotionSensor>("Industria",20,25);
    auto sensor7 = std::make_shared<GasSensor>("Industria","IBUT",20.0f);

    // alarms
    auto call1 = std::make_shared<CallFireBrigade>();
    auto call2 = std::make_shared<Evacuate>();
    auto call3 = std::make_shared<CallPolice>();
    auto call4 = std::make_shared<TurnOnLights>();

    // adding components
    building1->addComponent(level1);
    building1->addComponent(level2);
    building1->addComponent(sensor5);
    level1->addComponent(room1);
    level1->addComponent(sensor6);
    level2->addComponent(room2);
    level2->addComponent(room3);
    level2->addComponent(sensor7);
    room1->addComponent(sensor1);
    room2->addComponent(sensor2);
    room2->addComponent(sensor3);
    room3->addComponent(sensor4);

    // adding alarms
    sensor1->addAlarm(call1);
    sensor1->addAlarm(call2);
    sensor1->addAlarm(call3);
    sensor1->addAlarm(call4);
    sensor2->addAlarm(call3);
    sensor2->addAlarm(call4);
    sensor3->addAlarm(call1);
    sensor6->addAlarm(call1);
    sensor7->addAlarm(call2);
    sensor7->addAlarm(call4);

    /* DEMO */

    std::cout << ">>> Triggering all sensors in building 1" << std::endl;
    std::cout << building1->trigger() << std::endl;

    std::cout << ">>> Activating all sensors in builing 1" << std::endl << std::endl;
    ++*building1;

    std::cout << ">>> Deactivating all sensors in room 2" << std::endl << std::endl;
    --*room2;

    std::cout << ">>> Triggering all sensors in building 1" << std::endl;
    std::cout << building1->trigger() << std::endl;

    std::cout << ">>> Activating all sensors in room 2" << std::endl << std::endl;
    ++*room2;

    std::cout << ">>> Triggering all sensors in room 2" << std::endl;
    std::cout << room2->trigger() << std::endl;

    std::cout << ">>> Triggering all sensors in level 1" << std::endl;
    std::cout << level1->trigger() << std::endl;

    std::cout << ">>> Getting all info in building 1 by ID" << std::endl;
    std::cout << building1->sortSensorsByID() << std::endl;

    std::cout << ">>> Getting all info in building 1 by vendor" << std::endl;
    std::cout << building1->sortSensorsByVendor() << std::endl;

    std::cout << ">>> Getting all info in building 1 by type" << std::endl;
    std::cout << building1->sortSensorsByType() << std::endl;

}
