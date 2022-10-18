/*
 * ListTestDriver.cpp
 *
 * Description: Test Driver for data collection List class.
 *
 * Author: alavergn
 * Created on: Sept. 2022
 *
 */

#include "List.h"
#include "Member.h"
#include <iostream>

using namespace std;

int main()
{

    // Test: List(), insert(), getElementCount(), printList(), remove(), removeAll(), ~List()

    // Test case 1:
    // Create a List of size CAPACITY (5) using default constructor.
    // Testing List()
    cout << endl
         << "Create a default List -> testing constructor List()." << endl;
    cout << "Expected Result: empty List." << endl;
    List *Members = new List();
    cout << "Actual Result: ";
    Members->printList();
    cout << endl;

    // Test case 2:
    // Insert 5 elements into the List.
    // Testing insert() and getElementCount()
    cout << endl
         << "Insert 5 elements into the List -> testing insert() and getElementCount()." << endl;
    string names[5] = {"Jane", "John", "Joe", "Jill", "Jack"};
    string phones[5] = {"111-111-1111", "222-222-2222", "333-333-3333", "444-444-4444", "555-555-5555"};
    string emails[5] = {"jane@gmail.com", "john@gmail.com", "joe@gmail.com", "jill@gmail.com", "jack@gmail.com"};
    string creditCards[5] = {"1111-1111-1111-1111", "2222-2222-2222-2222", "3333-3333-3333-3333", "4444-4444-4444-4444", "5555-5555-5555-5555"};

    for (int i = 0; i < 5; i++)
    {
        Member newMember = Member(names[i], phones[i], emails[i], creditCards[i]);
        Members->insert(newMember);
    }

    cout << "Expected Result: 5 elements in the List." << endl;
    cout << "Actual Result: " << Members->getElementCount() << " elements in the List." << endl;

    // Testing duplicate insert()

    Member duplicate = Member("Jane", "111-111-1111", "jane@gmail.com", "1111-1111-1111-1111");

    cout << endl
         << "Insert a duplicate element into the List -> testing duplicate insert()." << endl;
    cout << "Expected Result: duplicate insert() returns false." << endl;
    cout << "Actual Result: duplicate insert() returns " << Members->insert(duplicate) << "." << endl;

    // Test case 3:
    // Testing printList()
    cout << endl
         << "Printing the List -> testing printList()." << endl;
    cout << "Expected Result: List of 5 elements." << endl;
    cout << "Actual Result: " << endl;
    Members->printList();
    cout << endl;

    // Test case 4:
    // Testing search()
    cout << endl
         << "Searching for an element in the List -> testing search()." << endl;
    cout << "Searching for phone number 111-111-1111 -> testing search()." << endl;
    cout << "Expected Result: Element found." << endl;
    cout << "Actual Result: ";

    Member toSearch = Member("111-111-1111");
    Member *foundMember = Members->search(toSearch);

    if (foundMember != NULL)
    {
        cout << "Element found: " << endl;
        cout << *foundMember;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    cout << endl
         << "Searching for an element not in the List -> testing search()." << endl;
    cout << "Expected Result: Element not found." << endl;
    cout << "Actual Result: ";

    toSearch = Member("666-666-6666");
    foundMember = Members->search(toSearch);

    if (foundMember != NULL)
    {
        cout << "Element found: " << endl;
        cout << *foundMember;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    // Test case 5:
    // Testing remove()
    cout << endl
         << "Removing an element from the List -> testing remove()." << endl;
    cout << "Removing phone number 111-111-1111 -> testing remove()." << endl;
    cout << "Expected Result: Element removed." << endl;
    cout << "Actual Result: ";

    Member toRemove = Member("111-111-1111");
    bool removed = Members->remove(toRemove);

    if (removed)
    {
        cout << "Element removed." << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    cout << endl
         << "Printing the List -> Member 111-111-1111 should no longer be in the list." << endl;
    cout << "Expected Result: List of 4 elements." << endl;
    cout << "Actual Result: " << endl;
    Members->printList();

    cout << endl
         << "Removing an element not from the List -> testing remove()." << endl;
    cout << "Removing phone number 666-666-6666 -> testing remove()." << endl;

    cout << "Expected Result: Element not found." << endl;
    cout << "Actual Result: ";

    toRemove = Member("666-666-6666");
    removed = Members->remove(toRemove);

    if (removed)
    {
        cout << "Element removed." << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    // Test case 6:
    // Testing removeAll()
    cout << endl
         << "Removing all elements from the List -> testing removeAll()." << endl;
    cout << "Expected Result: Empty list." << endl;
    cout << "Actual Result: " << endl;

    Members->removeAll();

    Members->printList();

    // Test case 7:
    // Testing destructor

    cout << endl
         << "Testing destructor -> deleting the List." << endl;
    cout << "Expected Result: No memory leaks." << endl;
    cout << "Actual Result: " << endl;

    Members->~List();

    Members->printList();

    cout<<"No memory leaks"<<endl;

    cout<<"End of test"<<endl;

    return 0;
}