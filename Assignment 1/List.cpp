/*
 * List.cpp
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - No gaps in the list.
 *
 * Author: AL
 * Last modified: Sept. 2022
 */

// Worked on by Rohan Parmar, 301420874

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

// Description: Deallocate all elements in the data structure.
// Postcondition: elementCount = 0 and elements points to NULL.
void List::clear() 
{
    delete[] elements;
    elements = NULL;
    elementCount = 0;
}

// Description: Default constructor
// Postcondition: elementCount = 0 and elements points to an array of CAPACITY Member objects.
List::List() 
{
    elementCount = 0;
    elements = new Member[CAPACITY];
}

// Description: Destructor
// Postcondition: All elements have been deallocated.
List::~List() 
{
    clear();
}


// Description: Returns the total number of elements currently stored in List.
unsigned int List::getElementCount() const 
{
    return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted in its proper place in List
//                and elementCount has been incremented.
bool List::insert( Member& newElement ) 
{
    if (elementCount == CAPACITY) 
    {
        return false;
    }
    else 
    {
        elements[elementCount] = newElement;
        elementCount++;
        return true;
    }
}

// Description: Remove an element.
// Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
//                and elementCount has been decremented.
bool List::remove( Member& toBeRemoved ) 
{
    if (elementCount == 0) 
    {
        return false;
    }
    else 
    {
        for (int i = 0; i < elementCount; i++) 
        {
            if (elements[i] == toBeRemoved) 
            {
                elements[i] = elements[elementCount - 1];
                elementCount--;
                return true;
            }
        }
        return false;
    }
}

// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll() 
{
    clear();
}

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Member* List::search( Member& target ) 
{
    for (int i = 0; i < elementCount; i++) 
    {
        if (elements[i] == target) 
        {
            return &elements[i];
        }
    }
    return NULL;
}

// Description: Prints all elements stored in List by descending order of search key.
void List::printList() 
{
    for (int i = 0; i < elementCount; i++) 
    {
        cout << elements[i] << endl;
    }
}

