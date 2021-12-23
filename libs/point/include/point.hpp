#pragma once
#include <iostream>
// Point header
class Point
{
private:
    float x;
    float y;

public:
    // Constructors
    Point();
    Point(float x, float y);
    Point(const Point &other);
    Point &operator=(const Point &other);

    // Getters
    float getX() const;
    float getY() const;

    // Setters
    void setX(float x);
    void setY(float y);

    // Operators
    Point &operator+=(const Point &other);
    Point operator+(const Point &other) const;

    // Destructor
    ~Point();

    // Extra
    void print();
    // override cout
    friend std::ostream &operator<<(std::ostream &os, const Point &point);
};
