/*
 * BinaryHeap.h
 *
 * Description: ____________ Binary Heap ADT class.
 *
 * Class Invariant:  Always a ____________ Binary Heap.
 *
 * Author:
 * Last Modification: Oct. 2022
 *
 */

#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

template <class ElementType>

class BinaryHeap
{
private:
    ElementType *elements; // Array of elements in the heap
    int elementCount;      // Number of elements in the heap
    int capacity;          // Capacity of the array

public:
    // Description: Default constructor
    BinaryHeap();

    // Description: Removes (but does not return) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(log2 n)
    void remove();

    // Utility method
    // Description: Recursively put the array back into a Maximum Binary Heap.
    void reHeapDown(unsigned int indexOfRoot);

    // Description: Returns the number of elements in this Binary Heap.
    // Postcondition: This Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    unsigned int getElementCount() const;

    // Description: Returns true if this Binary Heap is empty, otherwise false.
    // Postcondition: This Binary Heap is unchanged by this operation.
    // Time Efficiency: O(1)
    bool isEmpty() const;

    // Description: Resizes the array to double its current capacity.
    // Postcondition: The array is resized to double its current capacity.
    // Time Efficiency: O(n)
    void resize();

    // Utility method
    // Description: Recursively put the array back into a Maximum Binary Heap.
    void reHeapUp(unsigned int indexOfLastElement);

    // Description: Inserts newElement into the Binary Heap.
    //              It returns true if successful, otherwise false.
    // Time Efficiency: O(log2 n)
    bool insert(ElementType &newElement);

    // Description: Retrieves (but does not remove) the necessary element.
    // Precondition: This Binary Heap is not empty.
    // Postcondition: This Binary Heap is unchanged.
    // Exceptions: Throws EmptyDataCollectionException if this Binary Heap is empty.
    // Time Efficiency: O(1)
    ElementType &retrieve() const;

    // Description: Prints the contents of the Binary Heap.
    // Postcondition: This Binary Heap is unchanged.
    // Time Efficiency: O(n)
    void print() const;
};

#endif