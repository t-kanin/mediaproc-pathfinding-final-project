#include "component.h"

int Component::nextID = 1;

Component::Component(Entity entity): entity{entity}
{
    ID = nextID;
    nextID++;
}

Component::~Component() {}

int Component::getID() const
{
    return ID;
}

std::string Component::getInfo() const
{
    std::stringstream result;
    result << "ID: " << getID() << std::endl;
    return result.str();
}

Entity Component::getEntity() const
{
    return entity;
}

std::ostream & operator<<(std::ostream & ss, Component & component)
{
  ss << component.getInfo();
  return ss;
}





