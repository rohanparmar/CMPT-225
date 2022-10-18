/*
 * Circle.cpp
 *
 * Description: This class models a circle ...
 * Class Invariant: ???
 *
 * Author: Rohan Parmar
 * Creation date: Who cares
 */

#include <iostream>
#include "Circle.h"
#include <math.h>

using namespace std;

// Default constructor
Circle::Circle()
{
    radius = 10;
    x_coordinate = 0;
    y_coordinate = 0;
}

// Parameterized constructor
Circle::Circle(int x, int y, int r)
{
    radius = r;
    x_coordinate = x;
    y_coordinate = y;
}

// Destructor
Circle::~Circle()
{
    // Nothing to do here
}

// Accessors
int Circle::getRadius() const
{
    return radius;
}

int Circle::getX() const
{
    return x_coordinate;
}

int Circle::getY() const
{
    return y_coordinate;
}

// Mutators
void Circle::setRadius(int r)
{
    radius = r;
}

void Circle::move(int x, int y)
{
    x_coordinate = x;
    y_coordinate = y;
}

// Description: Returns the area of this circle
// Postcondition: Returns the area of this circle
double Circle::area() const
{
    return 3.14 * radius * radius;
}

void Circle::displayCircle() const
{
    cout << "Circle: (" << x_coordinate << "," << y_coordinate << ") " << radius << endl;
}

bool Circle::intersect(Circle otherCircle)
{
    double distance = sqrt(pow((x_coordinate - otherCircle.getX()), 2) + pow((y_coordinate - otherCircle.getY()), 2));
    if (distance <= radius + otherCircle.getRadius())
    {
        return true;
    }
    else
    {
        return false;
    }
}
