/*  Queue.h -> Queue ADT class definition
 *
 *   Author: Rohan Parmar, Nyls Poonoosamy
 *   Date: 3/11/2022
 *
 *
 *
 */

#ifndef QUEUE_H
#define QUEUE_H

#include "Event.h"
#include "EmptyDataCollectionException.h"
#include <iostream>

template <class ElementType>
class Node
{
public:
    ElementType item;
    Node *next;

    // Description: Default Node constructor
    // Postcondition: Creates an empty node
    Node()
    {
        this->next = NULL;
    }

    // Description: Parameterized Node constructor
    // Postcondition: Creates a node with item set to newItem
    Node(ElementType &newItem)
    {
        item = newItem;
        this->next = NULL;
    }

    // Description: Parameterized Node constructor
    // Postcondition: Creates a node with item set to newItem and next set to nextNodePtr
    Node(ElementType &newItem, Node *nextNodePtr)
    {
        item = newItem;
        this->next = nextNodePtr;
    }
};

template <class ElementType>
class Queue
{
private:
    int elementCount;
    Node<ElementType> *front;
    Node<ElementType> *back;

public:
    // Node::Node()
    // {
    //     next = NULL;
    // }

    // Node::Node(ElementType &newItem)
    // {
    //     item = newItem;
    //     next = NULL;
    // }

    // Node::Node(ElementType &newItem, Node *nextNodePtr)
    // {
    //     item = newItem;
    //     next = nextNodePtr;
    // }

    /******* Start of Queue Public Interface *******/

    // Description: Default constructor
    // Postcondition: Creates an empty queue
    Queue();

    // Description: Destructor
    // Postcondition: Deallocates all of the memory used by the queue
    ~Queue();

    // Class Invariant:  FIFO or LILO order

    // Description: Returns true if this Queue is empty, otherwise false.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Returns the number of elements in this Queue.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(1)
    int getElementCount() const;

    // Description: Inserts newElement at the "back" of this Queue
    //              (not necessarily the "back" of this Queue's data structure)
    //              and returns true if successful, otherwise false.
    // Time Efficiency: O(1)
    bool enqueue(ElementType &newElement);

    // Description: Removes (but does not return) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns (but does not remove) the element at the "front" of this Queue
    //              (not necessarily the "front" of this Queue's data structure).
    // Precondition: This Queue is not empty.
    // Postcondition: This Queue is unchanged by this operation.
    // Exception: Throws EmptyDataCollectionException if this Queue is empty.
    // Time Efficiency: O(1)
    ElementType &peek() const;

    // Description: Prints the content of this Queue.
    // Postcondition: This Queue is unchanged by this operation.
    // Time Efficiency: O(n)
    void printQueue() const;

    /******* End of Queue Public Interface *******/
};

#endif