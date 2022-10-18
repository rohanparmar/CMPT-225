/*
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Rohan Parmar
 * Date: 01/10/2022
 */

class Stack
{

private:
    // Description:  Nodes for a singly-linked list
    class StackNode
    {
    public:
        int data;
        StackNode *next;
    };

    /* Put your code here! */

    StackNode *head;

public:
    // Description: Default constructor
    Stack();

    // Description: Destructor
    ~Stack();

    // Description: Returns true if this Stack is empty otherwise false.
    // Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
    // O(n) in this case because we have to traverse the list to find the top, since head is at the bottom
    bool isEmpty() const;

    // Description: Returns the top element of the Stack
    // Precondition: Stack is not empty
    // Postcondition: Stack is unchanged
    // Exceptions: Throws EmptyStackException if Stack is empty
    // Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
    // O(n) in this case because we have to traverse the list to find the top, since head is at the bottom

    int &peek() const;

    // Description: Adds newElement to the top of the Stack
    // Returns true if the addition is successful, false otherwise
    // Precondition: Stack is not full, element is of the same type as the Stack
    // Postcondition: newElement is at the top of the Stack
    // Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
    // O(n) in this case because we have to traverse the list to find the top, since head is at the bottom

    bool push(int &newElement);

    // Description: Removes the top element of the Stack
    // Returns true if the removal is successful, false otherwise
    // Precondition: Stack is not empty
    // Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
    // O(n) in this case because we have to traverse the list to find the top, since head is at the bottom
    bool pop();

    // Description: Removes and returns the top element of the Stack
    // Precondition: Stack is not empty
    // Exceptions: Throws EmptyStackException if Stack is empty
    // Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
    // O(n) in this case because we have to traverse the list to find the top, since head is at the bottom
    int &popAndReturn();

    // Description: Removes all elements from the Stack
    // Returns true if the removal is successful, false otherwise
    // Precondition: Stack is not empty
    // Time Efficiency: O(n)
    bool popAll();

    // Description: Prints the contents of the Stack to the console
    // Time Efficiency: O(n)
    void printStack() const;

    /* Put your code here! */
};
