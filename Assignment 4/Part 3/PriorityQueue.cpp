/*  PriorityQueue.cpp -> PriorityQueue ADT class definition
 *  This is a priority queue class definition that uses the BinaryHeap class
 *  as a wrapper method to implement the priority queue ADT.
 *   Author: Rohan Parmar
 *   Date: 3/11/2022
 *
 *
 *
 */

#include "PriorityQueue.h"
#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include "Event.h"
#include <iostream>

using namespace std;

// Description: Default constructor
template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue()
{
}

// Description: Destructor
// Postcondition: Deallocates the memory used by the priority queue
template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue()
{
    heap.~BinaryHeap();
    delete heap;
}

// Description: Returns true if this Priority Queue is empty, otherwise false.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const
{
    return heap.isEmpty();
}

// Description: Inserts newElement into the Binary Heap.
//              It returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(ElementType &newElement)
{
    bool success = heap.insert(newElement);
    return success;
}

// Description: Removes (but does not return) the element with the next
//              "highest" priority value from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Exception: Throws EmptyDataCollectionException if Priority Queue is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void PriorityQueue<ElementType>::dequeue()
{
    if (heap.isEmpty())
    {
        throw EmptyDataCollectionException("Priority Queue is empty");
    }
    else
    {
        heap.remove();
    }
}

// Description: Returns (but does not remove) the element with the next
//              "highest" priority from the Priority Queue.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &PriorityQueue<ElementType>::peek() const
{
    if (heap.isEmpty())
    {
        throw EmptyDataCollectionException("Priority Queue is empty");
    }
    else
    {
        return heap.retrieve();
    }
}

// Description: Prints the contents of the Priority Queue to the console window.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(n)
template <class ElementType>
void PriorityQueue<ElementType>::print() const
{
    heap.print();
}

// Description: Returns the number of elements in the Priority Queue.
// Postcondition: This Priority Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const
{
    return heap.getElementCount();
}