/*
 * Circle.h
 *
 * Description: This class models a circle ...
 * Class Invariant: ???
 *
 * Author: Rohan Parmar
 * Creation date: Who cares
 */

class Circle
{

private:
    // Everything that follows is private and cannot be "seen" and
    // directly accessed from outside the class.
    // To access these private data members, client code needs to use the getters and setters.

    int x_coordinate;
    int y_coordinate;
    double radius;

    // Some classes have private methods like this Temperature class. This one doesn't!

public:
    // Everything that follows is public and can be "seen" and directly accessed
    // from outside the class (from client code).

    // Default constructor
    // Note that the default constructor has no parameters.
    Circle();

    // Parameterized constructor
    // Description: Create a new circle with the given values.
    Circle(int x, int y, double rad);

    // Getters return information about the circle.
    // Note the const at the end of the method.
    // This guarantees that the method cannot alter the member variables.
    int getX() const;
    int getY() const;
    double getRadius() const;

    // Setters change the values of the class' data members.
    void move(int horiz, int vert);

    void setRadius(double r);

    // Description: Compute and return the area of "this" circle.
    double computeArea() const;

    // Description: Prints the circle's y_coordinate and x_coordinate.
    void displayCircle() const;

    bool intersect(Circle C);

}; // Note the ";" - don't forget it!
   // End of Circle.h