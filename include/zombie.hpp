#pragma once

#include "../libs/point/include/point.hpp"
#include "entity.hpp"
#include "player.hpp"

// forward declaration
class Player;
// Class Zombie that inherits from Entity
class Zombie : public Entity
{

private:
    int health;

public:
    Zombie(Point position, Point velocity, int health);
    // Copy constructor
    Zombie(const Zombie &other);
    // Copy assignment constructor
    Zombie &operator=(const Zombie &other);
    // Override move function
    void move();

    // Setting the health
    void setHealth(int health);
    // Getting the health
    int getHealth();
    // override cout
    friend std::ostream &operator<<(std::ostream &os, const Zombie &zombie);
    // attack player
    void attack(Player &player);
};