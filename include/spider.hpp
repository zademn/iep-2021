#pragma once
#include "../libs/point/include/point.hpp"
#include "entity.hpp"

// Class Spider that inherits from Entity and can climb walls

class Spider : public Entity
{
private:
    bool climbing;

public:
    Spider(Point position, Point velocity);
    Spider(const Spider &other);
    Spider &operator=(const Spider &other);
    // Override move function
    void move();
    // A function that makes the spider climb a wall
    void climb();
    // A function that makes the spider fall down
    void fall();
    // Override cout
    friend std::ostream &operator<<(std::ostream &os, const Spider &spider);
};