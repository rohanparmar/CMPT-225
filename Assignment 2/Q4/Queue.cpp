/*
 * Queue.cpp - Does not work well!
 *
 * Description: Array-based implementation of Queue as an ADT class
 * Class Invariant: Queue maintained in FIFO order
 *
 * Author: Rohan Parmar
 * Date: 03/10/2022
 */

#include <iostream>
#include "Queue.h"

using std::cout;
using std::endl;

// Description: Constructor
Queue::Queue()
{
    elements = new int[INITIAL_CAPACITY];
}

// Description: Destructor
Queue::~Queue()
{
    delete[] elements;
    elements = nullptr;
}

// Description: sets capacity to new capacity
// Precondition: newCapacity > 0
// Postcondition: Queue's capacity is now newCapacity
void Queue::setCapacity(unsigned int newCapacity)
{
    capacity = newCapacity;
}

// Description: resizes the Queue to a new capacity
// Precondition: newCapacity > 0
// Postcondition: Queue's capacity is now newCapacity
int *Queue::resizeHigher(int *elements)
{

    setCapacity(capacity * 2);

    int *newElements = new int[capacity];
    int newIndex = 0;

    if (frontindex < backindex)
    {
        for (int i = 0; i < elementCount; i++)
        {
            newElements[i] = elements[i];
        }
    }
    else
    {
        for (int j = frontindex; j < elementCount; j++)
        {
            newElements[newIndex] = elements[j];
            newIndex++;
        }
        for (int k = 0; k <= backindex; k++)
        {
            newElements[newIndex] = elements[k];
            newIndex++;
        }
    }
    frontindex = 0;
    backindex = elementCount;
    delete[] elements;
    elements = newElements;
    return elements;
}

// Description: Inserts element x at the back of Queue
// Time Efficiency: O(1)
void Queue::enqueue(int x)
{
    if (elementCount == capacity) //|| (frontindex == 0 && backindex == capacity - 1) || (frontindex == backindex + 1))
    {
        cout << "Overflow, resizing array to higher capacity" << endl;
        elements = resizeHigher(elements);
        // capacity *= 2;
    }
    // cout << endl;
    // cout << "Element Count: " << elementCount << endl;
    // cout << "Capacity: " << capacity << endl;
    elements[backindex] = x;
    // cout << endl;
    // cout << "Element added: " << elements[backindex] << endl;
    // cout << "frontindex: " << frontindex << endl;
    // cout << "backindex: " << backindex << endl;
    backindex = (backindex + 1) % capacity;
    // cout << "new backindex: " << backindex << endl;
    // cout << endl;
    elementCount++;
    return;
}

// Description: resizes the Queue to a lower capacity
// Precondition: newCapacity > 0
// Postcondition: Queue's capacity is now newCapacity
int *Queue::resizeLower(int *elements)
{
    setCapacity(capacity / 2);

    int *newElements = new int[capacity];
    int newIndex = 0;

    if (frontindex < backindex)
    {
        for (int i = frontindex; i < backindex; i++)
        {
            newElements[newIndex] = elements[i];
            newIndex++;
        }
    }
    else
    {
        for (int j = frontindex; j < elementCount; j++)
        {
            newElements[newIndex] = elements[j];
            newIndex++;
        }
        for (int k = 0; k <= backindex; k++)
        {
            newElements[newIndex] = elements[k];
            newIndex++;
        }
    }

    // for (int i = 0; i < elementCount; i++)
    // {
    //     newElements[i] = elements[temp];
    //     temp = (temp + 1) % capacity;
    // }
    // for (int i = frontindex; i <= backindex; i++)
    // {
    //     newElements[i] = elements[i];
    // }
    frontindex = 0;
    backindex = elementCount;
    delete[] elements;
    elements = newElements;
    // capacity /= 2;
    return elements;
}

// Description: Removes the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
void Queue::dequeue()
{
    if (elementCount <= capacity / 4)
    {
        cout << "Array too big, resizing array to lower capacity" << endl;
        elements = resizeLower(elements);
    }

    // cout << endl;
    // cout << "Element Count: " << elementCount << endl;
    // cout << "Capacity: " << capacity << endl;
    // cout << "Element removed: " << elements[frontindex] << endl;
    // cout << "frontindex: " << frontindex << endl;
    // cout << "backindex: " << backindex << endl;
    frontindex = (frontindex + 1) % capacity;
    // cout << "new frontindex: " << frontindex << endl;
    // cout << endl;
    elementCount--;
}

// Description: Returns a copy of the frontmost element
// Precondition: Queue not empty
// Time Efficiency: O(1)
int Queue::peek() const
{
    return elements[frontindex];
}

// Description: prints the content of the Queue
// Time Efficiency: O(n)
void Queue::print() const
{
    if (elementCount == 0)
    {
        cout << "Queue is empty!" << endl;
    }
    else
    {
        // cout << "front index: " << frontindex << endl;
        // cout << "back index: " << backindex << endl;
        cout << "Queue's content: ";

        // for (int i = frontindex; i != backindex; i = (i + 1) % capacity)
        // {
        //     cout << elements[i] << " ";
        // }

        for (int i = frontindex; i < frontindex + elementCount; i = (i + 1) % capacity)
        {
            cout << elements[i] << " ";
        }

        // if (frontindex < backindex)
        // {
        //     for (int i = frontindex; i < backindex; i++)
        //     {
        //         cout << elements[i] << " ";
        //     }
        // }
        // else
        // {
        //     for (int j = frontindex; j < backindex; j++)
        //     {
        //         cout << elements[j] << " ";
        //     }
        //     for (int k = 0; k < backindex; k++)
        //     {
        //         cout << elements[k] << " ";
        //     }
        // }
        cout << endl;
    }
}

// Description: Returns true if and only if Queue empty
// Time Efficiency: O(1)
bool Queue::isEmpty() const
{
    return elementCount == 0;
}
