/*  Queue.cpp -> Queue ADT class definition
 *
 *   Author: Rohan Parmar, Nyls Poonoosamy
 *   Date: 3/11/2022
 *
 *
 *
 */

#include "Queue.h"

using namespace std;

// Description: Default Queue constructor
// Postcondition: Creates an empty queue
template <class ElementType>
Queue<ElementType>::Queue()
{
    // set back and front of queue to NULL
    front = NULL;
    back = NULL;
    // set elementCount to 0
    elementCount = 0;
}

// Description: Destructor
// Postcondition: Deallocates all the memory used by the queue
template <class ElementType>
Queue<ElementType>::~Queue()
{
    // while queue is not empty, call dequeue()
    while (!isEmpty())
        dequeue();
}

// Description: Returns true if this Queue is empty, otherwise false.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::isEmpty() const
{
    // if elementCount == 0, queue is empty
    return (elementCount == 0);
}

// Description: Returns the number of elements in this Queue.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
int Queue<ElementType>::getElementCount() const
{
    // return elementCount
    return elementCount;
}

// Description: Inserts newElement at the "back" of this Queue
//              (not necessarily the "back" of this Queue's data structure)
//              and returns true if successful, otherwise false.
// Time Efficiency: O(1)
template <class ElementType>
bool Queue<ElementType>::enqueue(ElementType &newElement)
{
    // make newNode with assigned element
    Node<ElementType> *newNode = new Node<ElementType>(newElement);
    // if queue is empty
    if (isEmpty())
    {
        // set the first node as the newNode
        front = newNode;
        back = front;
    }
    else
    {
        // make newNode the first node in queue
        back->next = newNode;
        back = back->next;
    }
    // increment elementCount
    elementCount++;

    // enqueue works
    return true;
}

// Description: Removes (but does not return) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
void Queue<ElementType>::dequeue()
{
    // if queue is empty
    if (isEmpty())
        throw EmptyDataCollectionException("Queue is empty");

    // create temp for front of queue
    Node<ElementType> *temp = front;
    // make front go do the next node
    front = front->next;
    // delete temp and decrement elementCount
    delete temp;
    temp = NULL;
    elementCount--;
}

// Description: Returns (but does not remove) the element at the "front" of this Queue
//              (not necessarily the "front" of this Queue's data structure).
// Precondition: This Queue is not empty.
// Postcondition: This Queue is unchanged by this operation.
// Exception: Throws EmptyDataCollectionException if this Queue is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &Queue<ElementType>::peek() const
{
    if (isEmpty())
        throw EmptyDataCollectionException("Queue is empty");
    // return NULL;
    // return item at front
    return front->item;
}

// Description: Prints the content of this Queue.
// Postcondition: This Queue is unchanged by this operation.
// Time Efficiency: O(n)
template <class ElementType>
void Queue<ElementType>::printQueue() const
{

    Node<ElementType> *temp = front;
    // iterate through queue
    while (temp != NULL)
    {
        // print elements of queue
        cout << temp->item << " ";
        temp = temp->next;
    }
    cout << endl;
}