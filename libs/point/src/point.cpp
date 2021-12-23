#include <iostream>
#include <typeinfo>
#include "point.hpp"

// Constructor with initialization list
Point::Point(float x, float y) : x(x), y(y) {}
// Default constructor that initialized fields
Point::Point() : x(0), y(0) {}
// Copy constructor
Point::Point(const Point &other) : x(other.x), y(other.y) {}

// Copy assignement constructor
Point &Point::operator=(const Point &other)
{
    // Identity test: if a self assignement do nothing
    if (this == &other)
    {
        std::cout << "Assigning " << *this << " to self\n";
        return *this;
    }

    this->x = other.x;
    this->y = other.y;
}
// Override add operator
Point Point::operator+(const Point &other) const
{
    return Point(this->x + other.x, this->y + other.y);
}
// Override add assignement operator
Point &Point::operator+=(const Point &other)
{
    this->x += other.x;
    this->y += other.y;
}

// Destructor
Point::~Point()
{
    std::cout << "Destroying "<< *this << "\n";
}
void Point::print()
{
    std::cout << "(" << this->x << "," << this->y << ")" << std::endl;
}
// Getters and setters
float Point::getX() const
{
    return this->x;
}
float Point::getY() const
{
    return this->y;
}
void Point::setX(float x)
{
    this->x = x;
}
void Point::setY(float y)
{
    this->y = y;
}
// override cout
std::ostream &operator<<(std::ostream &os, const Point &point)
{
    os << "(" << point.x << "," << point.y << ")";
    return os;
}
