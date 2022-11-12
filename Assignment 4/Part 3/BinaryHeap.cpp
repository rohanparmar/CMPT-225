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

using std::cout;
using std::endl;

// Description: Default constructor
template <class ElementType>
BinaryHeap<ElementType>::BinaryHeap()
{
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

    elements[0] = elements[elementCount - 1];
    elementCount--;
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
    return elementCount;
}

// Description: Returns true if this Binary Heap is empty, otherwise false.
// Postcondition: This Binary Heap is unchanged by this operation.
// Time Efficiency: O(1)
template <class ElementType>
bool BinaryHeap<ElementType>::isEmpty() const
{
    return (elementCount == 0);
}

// Description: Resizes the array to double its current capacity.
// Postcondition: The array is resized to double its current capacity.
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::resize()
{
    capacity *= 2;
    ElementType *newElements = new ElementType[capacity];

    for (int i = 0; i < elementCount; i++)
        newElements[i] = elements[i];

    delete[] elements;
    elements = newElements;
}

// Utility method
// Description: Recursively put the array back into a Minimum Binary Heap.
template <class ElementType>
void BinaryHeap<ElementType>::reHeapUp(unsigned int indexOfLastElement)
{
    if (indexOfLastElement > 0)
    {
        unsigned int indexOfParent = (indexOfLastElement - 1) / 2;

        if (elements[indexOfParent] > elements[indexOfLastElement])
        {
            ElementType temp = elements[indexOfParent];
            elements[indexOfParent] = elements[indexOfLastElement];
            elements[indexOfLastElement] = temp;

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
    if (elementCount == capacity)
    {
        cout << "resize() called from insert()" << endl;
        cout << "Capacity: " << capacity << endl;
        resize();
        cout << "New Capacity: " << capacity << endl;
    }

    elements[elementCount] = newElement;
    elementCount++;

    reHeapUp(elementCount - 1);

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

    return elements[0];
}

// Description: Prints the contents of the Binary Heap.
// Postcondition: This Binary Heap is unchanged.
// Time Efficiency: O(n)
template <class ElementType>
void BinaryHeap<ElementType>::print() const
{
    for (int i = 0; i < elementCount; i++)
        cout << elements[i] << " ";
    cout << endl;
}