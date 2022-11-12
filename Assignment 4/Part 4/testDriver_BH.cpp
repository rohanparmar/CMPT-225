/*  testDriver_BH.cpp -> Test driver for BinaryHeao ADT class
 *
 *   Author: Rohan Parmar
 *   Date: 3/11/2022
 *
 *
 *
 */

#include "BinaryHeap.h"
#include "BinaryHeap.cpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    BinaryHeap<int> *bh1 = new BinaryHeap<int>();

    cout << "Test Case 1 - Just created a Binary Heap" << endl;
    cout << endl;

    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Binary Heap size = 0" << endl;
    cout << "isEmpty() = true" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Binary Heap size: " << bh1->getElementCount() << endl;
    cout << "Binary Heap is empty: " << bh1->isEmpty() << endl;

    cout << endl
         << "Ending Test Case 1" << endl
         << endl;

    cout << "Test Case 2 - Adding 5 elements to the Binary Heap" << endl;
    for (int i = 0; i < 11; i++)
    {
        int num = rand() % 100;
        cout << "Adding " << num << " to the Binary Heap" << endl;
        bh1->insert(num);
    }

    cout << endl;
    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Binary Heap size = 5" << endl;
    cout << "isEmpty() = false" << endl;
    cout << "front() = 0" << endl;
    cout << "Content of Binary Heap: 7 9 44 30 23 73 72 78 58 49 40" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;

    cout << endl;
    cout << "Binary Heap size: " << bh1->getElementCount() << endl;
    cout << "Binary Heap is empty: " << bh1->isEmpty() << endl;
    cout << "Binary Heap front: " << bh1->retrieve() << endl;
    cout << "Binary Heap content: ";
    bh1->print();
    cout << endl;

    cout << endl
         << "Ending Test Case 2" << endl
         << endl;

    cout << "Test Case 3 - Removing 5 elements from the Binary Heap" << endl;
    for (int i = 0; i < 5; i++)
    {
        bh1->remove();
    }

    cout << endl;
    cout << "Expected Result: " << endl;

    cout << endl;
    cout << "Binary Heap size = 6" << endl;
    cout << "isEmpty: false" << endl;
    cout << "Binary Heap Front: 44" << endl;
    cout << "Content of Binary Heap: 44 49 72 78 58 73" << endl;

    cout << endl;
    cout << "Actual Result: " << endl;
    cout << endl;

    cout << "Binary Heap size: " << bh1->getElementCount() << endl;
    cout << "Binary Heap is empty: " << bh1->isEmpty() << endl;
    cout << "Binary Heap front: " << bh1->retrieve() << endl;
    cout << "Binary Heap content: ";
    bh1->print();
}