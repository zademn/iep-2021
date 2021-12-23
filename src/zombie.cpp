#include "../libs/point/include/point.hpp"
#include "zombie.hpp"
#include "player.hpp"

// Class Zombie that inherits from Entity
Zombie::Zombie(Point position, Point velocity, int health) : Entity(position, velocity)
{
    this->health = health;
}

// Copy constructor
Zombie::Zombie(const Zombie &other) : Entity(other), health(other.health) {}
// Copy assignment constructor
Zombie &Zombie::operator=(const Zombie &other)
{
    // Identity test: if a self assignement do nothing
    if (this == &other)
    {
        return *this;
    }

    // Copy the other object
    Entity::operator=(other);
    this->health = other.health;

    return *this;
}
// Override move function
void Zombie::move()
{
    // Call the parent move function
    Entity::move();
    // Add a random velocity between 0 and 5
    this->velocity.setX(this->velocity.getX() + (rand() % 10 - 5));
    this->velocity.setY(this->velocity.getY() + (rand() % 10 - 5));
}

// Setting the health
void Zombie::setHealth(int health)
{
    this->health = health;
}
// Getting the health
int Zombie::getHealth()
{
    return this->health;
}

// override the cout function
std::ostream &operator<<(std::ostream &os, const Zombie &zombie)
{
    os << "Zombie: " << zombie.position << " " << zombie.velocity << " " << zombie.health;
    return os;
}

// attack player
void Zombie::attack(Player &player)
{
    player.setHealth(player.getHealth() - 1);
}
