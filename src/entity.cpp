#include <iostream>
#include "entity.hpp"
#include "../libs/point/include/point.hpp"
//#include "point/include/point.hpp"

// Copy constructor
Entity::Entity(const Entity &other) : position(other.position), velocity(other.velocity) {}
// Copy assignement constructor
Entity &Entity::operator=(const Entity &other)
{
    // Identity test: if a self assignement do nothing
    if (this == &other)
    {
        return *this;
    }

    // Copy the other object
    this->position = other.position;
    this->velocity = other.velocity;

    return *this;
}
// A class Entity that has a position and a velocity
Entity::Entity(Point position, Point velocity) : position(position), velocity(velocity) {}
// Getter for position
Point Entity::getPosition() const { return this->position; }
// Getter for velocity
Point Entity::getVelocity() const { return this->velocity; }
// Setter for position
void Entity::setPosition(Point position) { this->position = position; }
// Setter for velocity
void Entity::setVelocity(Point velocity) { this->velocity = velocity; }
// Move the entity
void Entity::move()
{
    this->position += this->velocity;
}


// A function that returns a new position based on the current position and velocity
Point Entity::getNewPosition()
{
    return this->position + this->velocity;
}

//override the cout function
std::ostream &operator<<(std::ostream &os, const Entity &entity)
{
    os << "Position: ";
    os << entity.position;
    os << "Velocity: ";
    os << entity.velocity;
    return os;
}
