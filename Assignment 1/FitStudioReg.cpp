/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: AL
 * Last modified: Sept. 2022
 */

#include <iostream>
#include <string>
#include <cctype>
#include "Member.h"
#include "List.h"

using std::cout;

// Add a new member to the list of members
// Precondition: newMember is a valid Member object
// Postcondition: newMember is added to the list of members
void add(List *newMember)
{
    string phone;
    cout << "Enter the member's cell phone number: ";
    getline(cin, phone);
    Member newMem = Member(phone);

    bool success = newMember->insert(newMem);

    if (success)
    {
        cout << "Member added successfully!" << endl;
    }
    else
    {
        cout << "Member could not be added." << endl;
    }
};

void remove(List *member)
{
    string phone;
    cout << "Enter the phone number of the member: ";
    getline(cin, phone);

    Member toRemove = Member(phone);

    bool success = member->remove(toRemove);
    if (success)
    {
        cout << "Member removed successfully!" << endl;
    }
    else
    {
        cout << "Member could not be removed." << endl;
    }
};

void modify(List *member)
{
    string phone;
    cout << "Enter the phone number of the member: ";
    getline(cin, phone);

    Member toModify = Member(phone);
    Member *found = member->search(toModify);

    if (found != NULL)
    {
        bool modified = false;

        while (not modified)
        {
            char choice;
            cout << "What would you like to modify?" << endl;
            cout << "1. Name" << endl;
            cout << "2. Email" << endl;
            cout << "3. Credit Card" << endl;
            cout << "4. Exit" << endl;
            cin >> choice;
            cin.ignore();

            switch (choice)
            {
            case '1':
            {
                string name;
                cout << "Enter the new name: ";
                getline(cin, name);
                found->setName(name);
                break;
            }
            case '2':
            {
                string email;
                cout << "Enter the new email: ";
                getline(cin, email);
                found->setEmail(email);
                break;
            }
            case '3':
            {
                string creditCard;
                cout << "Enter the new credit card: ";
                getline(cin, creditCard);
                found->setCreditCard(creditCard);
                break;
            }
            case '4':
            {
                modified = true;
                break;
            }
            default:
            {
                cout << "Invalid choice." << endl;
                break;
            }
            }
        }
    }
    else
    {
        cout << "Member not found." << endl;
    }
};

void search(List *member)
{
    string phone;
    cout << "Enter the phone number of the member to be searched: ";
    getline(cin, phone);

    Member toSearch = Member(phone);
    Member *found = member->search(toSearch);

    if (found == NULL)
    {
        cout << "Member does not exist" << endl;
    }
    else
    {
        cout << "Member found!" << endl;
        cout << "Name: " << found->getName() << endl;
        cout << "Phone: " << found->getPhone() << endl;
        cout << "Email: " << found->getEmail() << endl;
        cout << "Credit Card: " << found->getCreditCard() << endl;
    }
};

void print(List *member)
{
    if (member->getElementCount() == 0)
    {
        cout << "There are no members in the list." << endl;
    }
    else
    {
        cout << "The members in the list are: " << endl;
        member->printList();
    }
};

int main()
{

    // Variables declaration
    List *Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (not done)
    {
        // Print menu to stdout
        cout << endl
             << "----Welcome to the Fitness Studio Registration System!" << endl;
        cout << endl
             << "Enter ..." << endl
             << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n"
             << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
        switch (input)
        {
        case 'a':
            add(Members);
            break;
        case 'r':
            remove(Members);
            break;
        case 's':
            search(Members);
            break;
        case 'm':
            modify(Members);
            break;
        case 'p':
            print(Members);
            break;
        case 'x':
            cout << "\n----Bye!\n"
                 << endl;
            done = true;
            break;
        default:
            cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    return 0;
}