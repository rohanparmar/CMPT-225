/*
Your program must:

Prompt the user to enter the size of the array.

Create a dynamically allocated array of that size.

Until the user has not finished ...

Prompt the user to enter the centre coordinates (x,y) and the radius of a circle.

Instantiate a Circle object with these values, then store this Circle object in the array.

Increment the count of elements.

Print the size of the array.

Print the number of Circle objects entered into the array.

Print the number of "empty" cell(s) in array, i.e., cells that do not contain Circle objects.

Print the content of the entire array, i.e., for each cell:

Print the value of the index of the cell.

If there is a Circle object stored in this cell, print it using the appropriate Circle method for this purpose.

If no Circle object is stored in this cell, print "This cell is empty.".

Question: How will you know whether there is a Circle object in a cell?
Answer: You can use your variables elementCount and arrSize for this purpose. Of course, you may have named these variables differently (yet descriptively).

Delete the dynamically allocated array before terminating the program.

This program returns 0.
*/

#include <iostream>

using namespace std;


class Circle
{
private:
    double x, y, radius;
public:
    Circle(double x, double y, double radius)
    {
        this->x = x;
        this->y = y;
        this->radius = radius;
    }
    double getRadius()
    {
        return radius;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void print()
    {
        cout << "Circle: (" << x << ", " << y << "), radius = " << radius << endl;
    }
};

int main()
{
    Circle * arr = NULL;        // Pointer variable, can point to an array of Circle
    unsigned int arrSize = 0;     // Variable to hold the number of cells in the array - Right now, initialized to 0 - User-defined
    unsigned int elementCount = 0; // Variable to hold the number of elements in the array - Right now, initialized to 0

    // Get the array size from the user using cin:
    // cin ... for you to complete!
    cout << "Enter the size of the array: "<<endl;
    cin >> arrSize;

    arr = new Circle[arrSize]; // Create a heap-allocated (dynamically allocated) array

    // Get the array elements from the user using cin:
    // cin ... for you to complete!
    cout << "Enter the elements of the array: "<<endl;
    
    for (int i = 0; i < arrSize; i++)
    {
        cout<<"Element "<<i+1<<": ";   
        cin >> arr[i];
        cout<<endl;
    }

    if ( arr != NULL )
    {
        // Get the array elements from the user using cin:
        cout << "The sum of the array elements is: " << sumArray(arr, arrSize) << endl;
        delete[] arr; // Deallocate the array
    }
    else
    {
        cout << "Error allocating memory for the array!" << endl;
    }
    // make sure the pointer the operator new returned is valid 
}