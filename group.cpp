#include "group.h"
#include <algorithm>

Group::Group(Entity aEntity) : Component()
{
    entity = aEntity;
}

bool Group::addComponent(std::shared_ptr<Component> newComponent)
{
    for (auto & component : components)
    {
        if (component->getID() == newComponent->getID()) return false;
    }
    components.push_back(newComponent);
    return true;
}

bool Group::removeComponent(std::shared_ptr<Component> removeComponent)
{
    auto itr = std::find(components.begin(), components.end(), removeComponent);
    if (itr != components.end())
    {
        components.erase(itr);
        return true;
    }
    else return false;
}

std::vector<std::shared_ptr<Component>> Group::getComponents() const
{
    return components;
}

std::string Group::sortSensorsByID()
{
    static std::vector<std::shared_ptr<Sensor>> allSensors;
    std::stringstream result;
    getSensorFromGroup(allSensors);
    std::sort(std::begin(allSensors), std::end(allSensors),
            [](std::shared_ptr<Component>  first, std::shared_ptr<Component>  second)
    {
        return first->getID() < second->getID();
    });
    for(auto & sensor: allSensors){
        result << *sensor;
    }
    return result.str();
}

std::string Group::sortSensorsByVendor()
{
    static std::vector<std::shared_ptr<Sensor>> allSensors;
    std::stringstream result;
    getSensorFromGroup(allSensors);
    std::sort(std::begin(allSensors), std::end(allSensors),
            [](std::shared_ptr<Sensor>  first, std::shared_ptr<Sensor>  second)
    {
        if(first->getVendor().compare(second->getVendor()) != 0)
            return first->getVendor() < second->getVendor();
        else
            return first->getID() < second->getID();
    });
    for(auto & sensor : allSensors){
        result << *sensor;
    }
    return result.str();
}

std::string Group::sortSensorsByType()
{
    static std::vector<std::shared_ptr<Sensor>> allSensors;
    std::stringstream result;
    getSensorFromGroup(allSensors);
    std::sort(std::begin(allSensors), std::end(allSensors),
            [](std::shared_ptr<Sensor>  first, std::shared_ptr<Sensor>  second)
    {
        if (first->getType().compare(second->getType()) != 0)
            return first->getType() < second->getType();
        else if(first->getVendor().compare(second->getVendor()) != 0)
            return first->getVendor() < second->getVendor();
        else
            return first->getID() < second->getID();
    });
    for(auto & sensor : allSensors){
        result << *sensor;
    }
    return result.str();
}

void Group::getSensorFromGroup(std::vector<std::shared_ptr<Sensor>> & allSensors)
{
    for(auto & component : components) {
        if(Entity::Sensor == component->getEntity())
            allSensors.push_back(std::dynamic_pointer_cast<Sensor>(component));
        else
            std::dynamic_pointer_cast<Group>(component)->getSensorFromGroup(allSensors);
    }
}

std::string Group::trigger() const
{
    std::stringstream result;
    for (auto &component : components)
    {
        result << component->trigger();
    }
    return result.str();
}

std::string Group::getInfo() const
{
    std::stringstream result;
    for (auto & component : components)
    {
        result << component->getInfo();
    }
    return result.str();
}

void Group::operator ++ ()
{
    for (auto & component : components)
    {
        ++*component;
    }
}

void Group::operator -- ()
{
    for (auto & component : components)
    {
        --*component;
    }
}




