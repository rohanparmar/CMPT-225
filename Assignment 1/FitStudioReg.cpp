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
void add(List& memberList)
{
    memberList.insert(newMember);
};

void remove(List& Member)
{
    string phone;
    cout << "Enter the phone number of the member: ";
    getline(phone);
    Member.remove(phone);
};

void modify(List& Member)
{
    string phone;
    cout << "Enter the phone number of the member: ";
    getline(phone);
    Member.modify(phone);
};

void search(List& Member)
{
    string phone;
    cout << "Enter the phone number of the member: ";
    getline(phone);
    Member.search(phone);
};

void print(List& Member)
{
    Member.display();
};

int main() {

    // Variables declaration
    List* Members = new List();
    bool done = false;
    char input = 0;

    // Keep going until the user exits
    while (not done) {
        // Print menu to stdout
        cout << endl << "----Welcome to the Fitness Studio Registration System!" << endl;
        cout << endl << "Enter ..." << endl << endl;
        cout << "a -> to add a new member" << endl;
        cout << "r -> to remove a member" << endl;
        cout << "s -> to search for a member" << endl;
        cout << "m -> to modify the record of a member" << endl;
        cout << "p -> to print all members" << endl;
        cout << "x -> to exit\n" << endl;

        cout << "Your choice: ";
        cin >> input;
        cout << endl;
        input = tolower(input);
		switch(input) {
            case 'a': add(Members); break;
            case 'r': remove(Members); break;
            case 's': search(Members); break;
            case 'm': modify(Members); break;
            case 'p': print(Members); break;
            case 'x': cout << "\n----Bye!\n" << endl; done = true; break;
            default: cout << "Not sure what you mean! Please, try again!" << endl;
        }
    }
    return 0;
}