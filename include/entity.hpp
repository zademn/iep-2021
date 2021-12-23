#pragma once
#include "../libs/point/include/point.hpp"
// A class Entity that has a position and a velocity
class Entity
{
protected:
    Point position;
    Point velocity; // velocity is a vector (x,y)
public:
    Entity(Point position, Point velocity);
    // Copy constructor
    Entity(const Entity &other);
    // Copy assignment constructor
    Entity &operator=(const Entity &other);

    // Getter for position
    Point getPosition() const;
    // Getter for velocity
    Point getVelocity() const;
    // Setter for position
    void setPosition(Point position);
    // Setter for velocity
    void setVelocity(Point velocity);
    // Move the entity
    void move();

    // A function that returns a new position based on the current position and velocity
    Point getNewPosition();

    // Overload cout
    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);
};
