#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <vector>

#include "component.h"
#include "sensor.h"

class Group : public Component
{
public:
    Group(Entity entity = Entity::Building);
    bool addComponent(std::shared_ptr<Component>);
    bool removeComponent(std::shared_ptr<Component>);
    std::vector<std::shared_ptr<Component>> getComponents() const;
    std::string trigger() const override;
    std::string getInfo() const override;
    std::string sortSensorsByID();
    std::string sortSensorsByVendor();
    std::string sortSensorsByType();
    void operator ++ () override;
    void operator -- () override;

private:
    void getSensorFromGroup(std::vector<std::shared_ptr<Sensor>> & allSensors);
    std::vector<std::shared_ptr<Component>> components;
};

#endif // GROUP_H
