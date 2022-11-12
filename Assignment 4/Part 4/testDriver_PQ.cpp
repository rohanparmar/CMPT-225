/*  testDriver_PQ.cpp -> Test driver for PriorityQueue ADT class
 *
 *   Author: Rohan Parmar
 *   Date: 3/11/2022
 *
 *
 *
 */

#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
#include "Event.h"
#include <iostream>

using namespace std;

int main()
{
    PriorityQueue<int> *pq1 = new PriorityQueue<int>();

    cout << "Test Case 1 - Just created a priority queue" << endl;
    cout << endl;

    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Priority Queue size = 0" << endl;
    cout << "isEmpty() = true" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Priority Queue size: " << pq1->getElementCount() << endl;
    cout << "Priority Queue is empty: " << pq1->isEmpty() << endl;

    cout << endl
         << "Ending Test Case 1" << endl
         << endl;

    cout << "Test Case 2 - Adding 5 elements to the priority queue" << endl;
    for (int i = 0; i < 5; i++)
    {
        pq1->enqueue(i);
    }

    cout << endl;
    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Priority Queue size = 5" << endl;
    cout << "isEmpty() = false" << endl;
    cout << "front() = 0" << endl;
    cout << "Content of priority queue: 0 1 2 3 4" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Priority Queue size: " << pq1->getElementCount() << endl;
    cout << "Priority Queue is empty: " << pq1->isEmpty() << endl;
    cout << "Priority Queue front: ";
    cout << pq1->peek();
    cout << endl;
    cout << "Priority Queue content: ";
    pq1->print();
    cout << endl;

    // while (!pq1->isEmpty())
    // {
    //     pq1->peek();
    //     cout << " ";
    //     pq1->dequeue();
    // }
    // cout << endl;

    cout << endl
         << "Ending Test Case 2" << endl
         << endl;

    cout << "Test Case 3 - Removing 3 elements to the priority queue" << endl;
    for (int i = 0; i < 3; i++)
    {
        pq1->dequeue();
    }

    cout << endl;

    cout << "Expected Result: " << endl;

    cout << endl;

    cout << "Priority Queue size = 2" << endl;
    cout << "isEmpty() = false" << endl;
    cout << "front() = 3" << endl;
    cout << "Content of priority queue: 3 4" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Priority Queue size: " << pq1->getElementCount() << endl;
    cout << "Priority Queue is empty: " << pq1->isEmpty() << endl;
    cout << "Priority Queue front: ";
    cout << pq1->peek();
    cout << endl;
    cout << "Priority Queue content: ";
    pq1->print();
    cout << endl;
}