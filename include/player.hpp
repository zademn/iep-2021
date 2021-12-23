#pragma once

#include "../libs/point/include/point.hpp"
#include "zombie.hpp"
#include "entity.hpp"

// forward declaration
class Zombie;
// A class Player that inherits from Entity and can attack Zombie
class Player : public Entity
{
private:
    int health;

    // Copy constructor
    Player(const Player &other);
    // Copy assignment constructor
    Player &operator=(const Player &other);

public:
    Player(Point position, Point velocity);
    // Getter for health
    int getHealth() const;
    // Setter for health
    void setHealth(int health);
    // A function that attacks a zombie
    void attack(Zombie &zombie);

    // override cout
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
};
