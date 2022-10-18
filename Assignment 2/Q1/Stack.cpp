/*
 * Stack.cpp
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Rohan Parmar
 * Date: 01/10/2022
 */

#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

// Description: Default constructor

Stack::Stack()
{
    head = new StackNode;
    head->next = NULL;
    head->data = NULL;
}

// Description: Destructor

Stack::~Stack()
{
    StackNode *temp = NULL;
    temp = head;
    while (temp->next != NULL)
    {
        temp = head;
        head = head->next;
        delete (temp);
    }
    delete (head);
}

// Description: Returns true if this Stack is empty otherwise false.
// Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
// O(n) in this case because we have to traverse the list to find the top, since head is at the bottom

bool Stack::isEmpty() const
{
    if (head->next == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Description: Returns the top element of the Stack
// Precondition: Stack is not empty
// Postcondition: Stack is unchanged
// Exceptions: Throws EmptyStackException if Stack is empty
// Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
// O(n) in this case because we have to traverse the list to find the top, since head is at the bottom

int &Stack::peek() const
{
    if (isEmpty())
    {
        // throw EmptyStackException("Stack is empty");
        cout << "Stack is empty";
    }
    else
    {
        StackNode *temp = NULL;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        return temp->data;
    }
}

// Description: Adds newElement to the top of the Stack
// Returns true if the addition is successful, false otherwise
// Precondition: Stack is not full, element is of the same type as the Stack
// Postcondition: newElement is at the top of the Stack
// Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
// O(n) in this case because we have to traverse the list to find the top, since head is at the bottom

bool Stack::push(int &newElement)
{
    if (isEmpty())
    {
        StackNode *temp = new StackNode;
        temp->data = newElement;
        temp->next = NULL;
        head->next = temp;
        return true;
    }
    else
    {
        StackNode *temp = NULL;
        StackNode *toInsert = new StackNode;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = toInsert;
        toInsert->data = newElement;
        toInsert->next = NULL;
        return true;
    }
}

// Description: Removes the top element of the Stack
// Returns true if the removal is successful, false otherwise
// Precondition: Stack is not empty
// Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
// O(n) in this case because we have to traverse the list to find the top, since head is at the bottom

bool Stack::pop()
{
    if (isEmpty())
    {
        cout << "Underflow" << endl;
        return false;
    }

    else
    {
        StackNode *temp = NULL;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
        return true;
    }
}

// Description: Removes and returns the top element of the Stack
// Precondition: Stack is not empty
// Exceptions: Throws EmptyStackException if Stack is empty
// Time Efficiency: O(1) if head is at top, O(n) if head is at bottom
// O(n) in this case because we have to traverse the list to find the top, since head is at the bottom

int &Stack::popAndReturn()
{
    if (isEmpty())
    {
        // throw EmptyStackException("Stack is empty");
        cout << "Stack is empty";
    }
    else
    {
        StackNode *temp = NULL;
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        int data = temp->data;
        delete (temp->next);
        temp->next = NULL;
        return data;
    }
}

// Description: Removes all elements from the Stack
// Returns true if the removal is successful, false otherwise
// Precondition: Stack is not empty
// Time Efficiency: O(n)

bool Stack::popAll()
{
    if (isEmpty())
    {
        return false;
    }
    else
    {
        StackNode *temp = NULL;
        temp = head;
        while (temp != NULL)
        {
            temp = head;
            head = head->next;
            delete (temp);
        }
        return true;
    }
}

// Description: Prints the content of the Stack to the console
// Precondition: Stack is not empty
// Time Efficiency: O(n)

void Stack::printStack() const
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        StackNode *temp = NULL;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
            cout << temp->data << " ";
        }
        cout << endl;
    }
}