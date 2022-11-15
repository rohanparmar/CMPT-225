/*
 * BinaryHeap.cpp
 *
 * Description: Minimum Binary Heap ADT class.
 *
 * Class Invariant:  Always a Minimum Binary Heap.
 *
 * Author:
 * Last Modification: Oct. 2022
 *
 */

#include <iostream>
#include "BinaryHeap.h" // Header file
// #include "Event.h"

using std::cout;
using std::endl;

// Description: Default constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
    //set elementCount, total capacity and array for heap
    elementCount = 0;
    capacity = 10;
    elements = new ElementType[capacity];
}

// Description: Removes (but does not return) the necessary element.
// Precondition: This Binary Heap is not empty.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(log2 n)
template <class ElementType>
void BinaryHeap<ElementType>::remove()
{
    if (elementCount == 0)
        // throw EmptyDataCollectionException("remove() called with an empty BinaryHeap.");
        return;
    if (elementCount == 1)
    {
        //decrement elementCount and return
        elementCount--;
        return;
    }
    //set first index of array (elements) to the final index of array (elements)
    elements[0] = elements[elementCount - 1];
    //decrement elementCount
    elementCount--;
    //call reHeapDown from the first index
    reHeapDown(0);

    return;
}

// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapDown(unsigned int indexOfRoot)
{

    unsigned int indexOfMinChild = indexOfRoot;

    // Find indices of children.
    unsigned int indexOfLeftChild = 2 * indexOfRoot + 1;
    unsigned int indexOfRightChild = 2 * indexOfRoot + 2;

    // Base case: elements[indexOfRoot] is a leaf as it has no children
    if (indexOfLeftChild > elementCount - 1)
        return;

    // If we need to swap, select the smallest child
    // If (elements[indexOfRoot] > elements[indexOfLeftChild])
    if (!(elements[indexOfRoot] <= elements[indexOfLeftChild]))
        indexOfMinChild = indexOfLeftChild;

    // Check if there is a right child, is it the smallest?
    if (indexOfRightChild < elementCount)
    {
        // if (elements[indexOfMinChild] > elements[indexOfRightChild])
        if (!(elements[indexOfMinChild] <= elements[indexOfRightChild]))
            indexOfMinChild = indexOfRightChild;
    }

    // Swap parent with smallest of children.
    if (indexOfMinChild != indexOfRoot)
    {

        ElementType temp = elements[indexOfRoot];
        elements[indexOfRoot] = elements[indexOfMinChild];
        elements[indexOfMinChild] = temp;

        // Recursively put the array back into a heap
        reHeapDown(indexOfMinChild);
    }
    return;
}

// Description: Returns the number of elements in this Binary Heap.
// Postcondition: This Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
unsigned int BinaryHeap<ElementType>::getElementCount() const
{
    //return elementCount
    return elementCount;
}

// Description: Returns true if this Binary Heap is empty, otherwise false.
// Postcondition: This Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool BinaryHeap<ElementType>::isEmpty() const
{
    //if elementCount equals 0, return true
    return (elementCount == 0);
}

// Description: Resizes the array to double its current capacity.
// Postcondition: The array is resized to double its current capacity.
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::resize()
{
    //make new array with double capacity
    capacity *= 2;
    ElementType *newElements = new ElementType[capacity];

    //copy all elements from old array to new resized array
    for (int i = 0; i < elementCount; i++)
        newElements[i] = elements[i];

    //call destructor for old array 
    delete[] elements;
    //set elements to new array of double capacity
    elements = newElements;
}

// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfLastElement)
{
    //if index of lastElement is greater than 0
    if (indexOfLastElement > 0)
    {
        //reassign index of parent to indexofLastElement-1/2
        unsigned int indexOfParent = (indexOfLastElement - 1) / 2;

        //if value from index of last element is less than value from index of the parent
        if (elements[indexOfLastElement] <= elements[indexOfParent])
        {
            //create a temp to store value from index of parent
            ElementType temp = elements[indexOfParent];
            //swap value from index of parent to index of last element
            elements[indexOfParent] = elements[indexOfLastElement];
            elements[indexOfLastElement] = temp;

            //recursive call of reHeapUp with the parent to go up again
            reHeapUp(indexOfParent);
        }
    }

    // Base case: elements[indexOfLastElement] is the root
    if (indexOfLastElement == 0)
        return;
    return;
}

// Description: Inserts newElement into the Binary Heap.
//              It returns true if successful, otherwise false.
// Time Efficiency: O(log2 n)
template <class ElementType>
bool BinaryHeap<ElementType>::insert(ElementType &newElement)
{
    //if array is full, resize array by calling resize()
    if (elementCount == capacity)
    {
        //cout << "resize() called from insert()" << endl;
        //cout << "Capacity: " << capacity << endl;
        resize();
        //cout << "New Capacity: " << capacity << endl;
    }

    //set last index of elements to newElement
    elements[elementCount] = newElement;
    //increment elementCount
    elementCount++;
    //call reHeapUp function from last index to maintain the binary heap
    reHeapUp(elementCount - 1);

    //insert worked
    return true;
}

// Description: Retrieves (but does not remove) the necessary element.
// Precondition: This Binary Heap is not empty.
// Postcondition: This Binary Heap is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
// Time Efficiency: O(1)
template <class ElementType>
ElementType &BinaryHeap<ElementType>::retrieve() const
{
    if (elementCount == 0)
        // throw EmptyDataCollectionException();
        return elements[0];
    
    //return first index value
    return elements[0];
}

// Description: Prints the contents of the Binary Heap.
// Postcondition: This Binary Heap is unchanged.
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::print() const
{
    //print elements of heap
    for (int i = 0; i < elementCount; i++)
        cout << elements[i] << " ";
    cout << endl;
}