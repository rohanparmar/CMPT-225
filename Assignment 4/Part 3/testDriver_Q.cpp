/*  testDriver_Q.cpp -> Test driver for Queue ADT class
 *
 *   Author: Rohan Parmar
 *   Date: 3/11/2022
 *
 *
 *
 */

#include "Queue.h"
#include "Queue.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Queue<int> *q1 = new Queue<int>();

    cout << "Test Case 1 - Just created a queue" << endl;
    cout << endl;

    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Queue size = 0" << endl;
    cout << "isEmpty() = true" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Queue size: " << q1->getElementCount() << endl;
    cout << "Queue is empty: " << q1->isEmpty() << endl;

    cout << endl
         << "Ending Test Case 1" << endl
         << endl;

    cout << "Test Case 2 - Adding 5 elements to the queue" << endl;
    for (int i = 0; i < 5; i++)
    {
        q1->enqueue(i);
    }

    cout << endl;
    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Queue size = 5" << endl;
    cout << "isEmpty() = false" << endl;
    cout << "front() = 0" << endl;
    cout << "Content of queue: 0 1 2 3 4" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Queue size: " << q1->getElementCount() << endl;
    cout << "Queue is empty: " << q1->isEmpty() << endl;
    cout << "Queue front: " << q1->peek() << endl;
    cout << "Printing queue: " << endl;
    q1->printQueue();

    cout << endl
         << "Ending Test Case 2" << endl
         << endl;

    cout << "Test Case 3 - Removing 3 elements from the queue" << endl;
    for (int i = 0; i < 3; i++)
    {
        q1->dequeue();
    }

    cout << endl;
    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Queue size = 2" << endl;
    cout << "isEmpty() = false" << endl;
    cout << "front() = 3" << endl;
    cout << "Content of queue: 3 4" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Queue size: " << q1->getElementCount() << endl;
    cout << "Queue is empty: " << q1->isEmpty() << endl;
    cout << "Queue front: " << q1->peek() << endl;
    cout << "Printing queue: " << endl;
    q1->printQueue();

    cout << endl
         << "Ending Test Case 3" << endl
         << endl;

    cout << endl;
    cout << "Testing destructor" << endl;
    q1->~Queue();

    delete q1;
    q1 = NULL;
}