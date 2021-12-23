#include "player.hpp"
#include "zombie.hpp"
#include "../libs/point/include/point.hpp"

// A class Player that inherits from Entity and can attack Zombie
Player::Player(Point position, Point velocity) : Entity(position, velocity), health(100) {}
// Copy constructor
Player::Player(const Player &other) : Entity(other.position, other.velocity), health(other.health) {}
// Copy assignment constructor
Player &Player::operator=(const Player &other)
{
}

// Getter for health
int Player::getHealth() const { return this->health; }
// Setter for health
void Player::setHealth(int health) { this->health = health; }
// A function that attacks a zombie
void Player::attack(Zombie &zombie)
{
    // Subtract health from zombie
    zombie.setHealth(zombie.getHealth() - 10);
}

// override cout
std::ostream &operator<<(std::ostream &os, const Player &player)
{
    os << "Player: " << player.position << " " << player.velocity << " " << player.health;
    return os;
}
