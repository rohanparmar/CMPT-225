/*
 * Queue.h - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Rohan Parmar
 * Date: 03/10/2022
 */

#ifndef QUEUE_H
#define QUEUE_H

class Queue
{

    /* You cannot remove/modify the data members below, but you can add to them. */

private:
    static unsigned int const INITIAL_CAPACITY = 6; // Constant INITIAL_CAPACITY
    int *elements;                                  // To do: replace this by int * elements -> Question 4.a)

    unsigned int elementCount = 0;            // Number of elements in the Queue - if you need it!
    unsigned int capacity = INITIAL_CAPACITY; // Actual capacity of the data structure (number of cells in the array)
    unsigned int frontindex = 0;              // Index of front element (next dequeued/peeked element)
    unsigned int backindex = 0;               // Index of where the next element will be enqueued

    /* You can add private methods. */

    // Description: resizes the Queue to a higher capacity
    // Precondition: newCapacity > 0
    // Postcondition: Queue's capacity is now newCapacity
    int *resizeHigher(int *elements);

    // Description: resizes the Queue to a lower capacity
    // Precondition: newCapacity > 0
    // Postcondition: Queue's capacity is now newCapacity
    int *resizeLower(int *elements);

    // Description: sets capacity to new capacity
    // Precondition: newCapacity > 0
    // Postcondition: Queue's capacity is now newCapacity
    void setCapacity(unsigned int newCapacity);

public:
    /* You cannot remove/modify the public methods below. This also applies to their documentation. */

    // Description: Constructor
    Queue();

    // Description: Destructor
    ~Queue();

    // Description: Inserts element x at the back of Queue
    // Time Efficiency: O(1)
    void enqueue(int x);

    // Description: Removes the frontmost element
    // Precondition: Queue not empty
    // Time Efficiency: O(1)
    void dequeue();

    // Description: Returns a copy of the frontmost element
    // Precondition: Queue not empty
    // Time Efficiency: O(1)
    int peek() const;

    // Description: prints the content of the Queue
    // Time Efficiency: O(n)
    void print() const;

    // Description: Returns true if and only if Queue empty
    // Time Efficiency: O(1)
    bool isEmpty() const;
};
#endif
