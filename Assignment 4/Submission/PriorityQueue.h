/*  PriorityQueue.h -> PriorityQueue ADT class definition
 *  This is a priority queue class definition that uses the BinaryHeap class
 *  as a wrapper method to implement the priority queue ADT.
 *   Author: Rohan Parmar, Nyls Poonoosamy
 *   Date: 3/11/2022
 *
 *
 *
 */

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BinaryHeap.h"
#include "EmptyDataCollectionException.h"
#include <iostream>

template <class ElementType>

class PriorityQueue
{
private:
    BinaryHeap<ElementType> heap;

public:
    /******* Start of Priority Queue Public Interface *******/

    // Description: Default constructor
    // Postcondition: Creates an empty priority queue
    PriorityQueue();

    // Description: Destructor
    // Postcondition: Deallocates the memory used by the priority queue
    ~PriorityQueue();

    // Description: Returns true if this Priority Queue is empty, otherwise false.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Inserts newElement in this Priority Queue and
    //              returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool enqueue(ElementType &newElement);

    // Description: Removes (but does not return) the element with the next
    //              "highest" priority value from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
    // Time Efficiency: O(log2 n)
    void dequeue();

    // Description: Returns (but does not remove) the element with the next
    //              "highest" priority from the Priority Queue.
    // Precondition: This Priority Queue is not empty.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
    // Time Efficiency: O(1)
    ElementType &peek() const;

    // Description: Prints the contents of the Priority Queue to the console window.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(n)
    void print() const;

    // Description: Returns the number of elements in the Priority Queue.
    // Postcondition: This Priority Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    int getElementCount() const;

    /*******  End of Priority Queue Public Interface *******/

}; // end PriorityQueue

#endif