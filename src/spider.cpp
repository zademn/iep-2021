#include "spider.hpp"
#include "../libs/point/include/point.hpp"

// Class Spider that inherits from Entity and can climb walls
Spider::Spider(Point position, Point velocity) : Entity(position, velocity), climbing(false) {}
// Copy constructor
Spider::Spider(const Spider &other) : Entity(other), climbing(other.climbing) {}
// Copy assigement constructor
Spider &Spider::operator=(const Spider &other)
{
    // Identity test: if a self assignement do nothing
    if (this == &other)
    {
        return *this;
    }

    // Copy the other object
    Entity::operator=(other);
    this->climbing = other.climbing;

    return *this;
}
// Override move function
void Spider::move()
{
    // Call the parent move function
    Entity::move();
    // Add a random velocity
    this->velocity.setX(this->velocity.getX() + (rand() % 10 - 5));
    this->velocity.setY(this->velocity.getY() + (rand() % 10 - 5));
    // If the spider is climbing, it can't move
    if (this->climbing)
    {
        this->velocity.setX(0);
        this->velocity.setY(0);
    }
}
// A function that makes the spider climb a wall
void Spider::climb()
{
    this->climbing = true;
}
// A function that makes the spider fall down
void Spider::fall()
{
    this->climbing = false;
}

// override cout
std::ostream &operator<<(std::ostream &os, const Spider &spider)
{
    os << "Spider: " << spider.position << " " << spider.velocity << " " << spider.climbing;
    return os;
}
