#ifndef COMPONENT_H
#define COMPONENT_H

#include <sstream>
#include <memory>
enum class Entity {Building, Level, Room, Sensor};
class Component
{
public:
    Component(Entity entity = Entity::Sensor);
    virtual ~Component();
    int getID() const;
    Entity getEntity() const;
    virtual std::string trigger() const = 0;
    virtual std::string getInfo() const;
    virtual void operator ++ () = 0;
    virtual void operator -- () = 0;

private:
    int ID;
    static int nextID;

protected:
    Entity entity;
};

std::ostream & operator<<(std::ostream & ss, Component & other);

#endif // COMPONENT_H
