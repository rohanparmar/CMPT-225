/*
 * FitStudioReg.cpp - Assignment 1
 *
 * Class Description: Fitness Studio Registration System
 *
 * Author: AL
 * Last modified: Sept. 2022
 */

#include "List.h"
#include "Member.h"
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// Description: validates the phone number
// Precondition: phone number must be 12 digits,
// and must be in the format of XXX-XXX-XXXX
// Postcondition: returns true if phone number is valid
bool validatePhone(string phone)
{
  if (phone.length() != 12)
  {
    return false;
  }
  else
  {
    for (int i = 0; i < phone.length(); i++)
    {
      if (i == 3 || i == 7)
      {
        if (phone[i] != '-')
        {
          return false;
        }
      }
      else
      {
        if (!isdigit(phone[i]))
        {
          return false;
        }
      }
    }
  }
  return true;
}

// Description: checks if the phone number is already in the list
// Precondition: phone number must be 12 digits,
// and must be in the format of XXX-XXX-XXXX and must be unique
// Postcondition: returns false if phone number is already in the list
bool isUnique(List *member, string phone)
{
  Member toSearch = Member(phone);
  Member *found = member->search(toSearch);

  if (found == NULL)
  {
    return true;
  }
  else
  {
    return false;
  }
}

// Add a new member to the list of members
// Precondition: member is a valid Member object
// Member must have a unique phone number ie no duplicates
// Postcondition: member is added to the list of members
void add(List *member)
{
  string phone;
  string name;
  string email;
  string creditCard;

  cout << "Enter the member's cell phone number: ";
  cin >> phone;
  cin.ignore(256, '\n');

  if (!validatePhone(phone))
  {
    phone = "000-000-0000";
  }

  cout << "Enter the member's name: ";
  cin >> name;
  cin.ignore(256, '\n');

  cout << "Enter the member's email address: ";
  cin >> email;
  cin.ignore(256, '\n');

  cout << "Enter the member's credit card number: ";
  cin >> creditCard;
  cin.ignore(256, '\n');

  if (!isUnique(member, phone))
  {
    cout << "Member already exists." << endl;
  }
  else
  {
    Member newMember(name, phone, email, creditCard);

    try
    {
      member->insert(newMember);
    }
    catch (const char *msg)
    {
      cout << msg << endl;
    }
  }
};

// Description: removes a member from the list of members
// Precondition: member is a valid Member object and must be in the list
// Postcondition: member is removed from the list of members
// void remove(List *member)
// {
//   string phone;
//   cout << "Enter the phone number of the member: ";
//   cin >> phone;
//   cin.ignore();

//   Member toRemove = Member(phone);

//   bool success = member->remove(toRemove);
//   if (success)
//   {
//     cout << "Member removed successfully!" << endl;
//   }
//   else
//   {
//     cout << "Member could not be removed." << endl;
//   }
// };

// Description: modifies the member's information
// Precondition: member is a valid Member object and must be in the list
// Postcondition: member's information is modified
// void modify(List *member)
// {
//   string phone;
//   cout << "Enter the phone number of the member: ";
//   cin >> phone;
//   cin.ignore();

//   Member toModify = Member(phone);
//   Member *found = member->search(toModify);

//   if (found != NULL)
//   {
//     bool modified = false;

//     while (not modified)
//     {
//       char choice;
//       cout << "What would you like to modify?" << endl;
//       cout << "1. Name" << endl;
//       cout << "2. Email" << endl;
//       cout << "3. Credit Card" << endl;
//       cout << "4. Exit" << endl;
//       cin >> choice;
//       cin.ignore();

//       switch (choice)
//       {
//         case '1':
//         {
//             string name;
//             cout << "Enter the new name: ";
//             getline(cin, name);
//             found->setName(name);
//             break;
//         }
//         case '2':
//         {
//             string email;
//             cout << "Enter the new email: ";
//             getline(cin, email);
//             found->setEmail(email);
//             break;
//         }
//         case '3':
//         {
//             string creditCard;
//             cout << "Enter the new credit card: ";
//             getline(cin, creditCard);
//             found->setCreditCard(creditCard);
//             break;
//         }
//         case '4':
//         {
//             modified = true;
//             break;
//         }
//         default:
//         {
//             cout << "Invalid choice." << endl;
//             break;
//         }
//       }
//     }
//   }
//   else
//   {
//     cout << "Member not found." << endl;
//   }
// };

// Description: searches for a member in the list of members
// Precondition: member is a valid Member object and must be in the list
// Member must have a unique phone number ie no duplicates
// Postcondition: member is found in the list of members and displayed
void search(List *member)
{
  string phone;
  cout << "Enter the phone number of the member to be searched: ";
  cin >> phone;
  cin.ignore();

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

// Description: displays all the members in the list of members
// Precondition: member is a valid Member object and must be in the list
// Postcondition: all members are displayed
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
  // List *Members = new List(unsigned int (*hFcn)(string));
  bool done = false;
  char input = 0;

  // Keep going until the user exits
  //   while (not done)
  //   {
  //     // Print menu to stdout
  //     cout << endl
  //          << "----Welcome to the Fitness Studio Registration System!" << endl;
  //     cout << endl
  //          << "Enter ..." << endl
  //          << endl;
  //     cout << "a -> to add a new member" << endl;
  //     cout << "r -> to remove a member" << endl;
  //     cout << "s -> to search for a member" << endl;
  //     cout << "m -> to modify the record of a member" << endl;
  //     cout << "p -> to print all members" << endl;
  //     cout << "x -> to exit\n"
  //          << endl;

  //     cout << "Your choice: ";
  //     cin >> input;
  //     cout << endl;
  //     input = tolower(input);
  //     switch (input)
  //     {
  //     case 'a':
  //       add(Members);
  //       break;
  //     // case 'r':
  //     //   remove(Members);
  //     //   break;
  //     case 's':
  //       search(Members);
  //       break;
  //     // case 'm':
  //     //   modify(Members);
  //     //   break;
  //     case 'p':
  //       print(Members);
  //       break;
  //     case 'x':
  //       cout << "\n----Bye!\n"
  //            << endl;
  //       done = true;
  //       break;
  //     default:
  //       cout << "Not sure what you mean! Please, try again!" << endl;
  //     }
  //   }
  //   // Members->removeAll();
  //   Members->~List();
  //   return 0;
  // }
  return 0;
}