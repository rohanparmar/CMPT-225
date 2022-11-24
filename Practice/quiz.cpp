/*
 * testDriver.cpp
 *
 * Description: Test drive the Data Collection ADT class.
 *
 * Author: AL
 * Date: Oct. 2022
 */

#include <iostream>
#include "UnableToInsertException.h"
#include "DataCollection.h"

using namespace std;

int main()
{
    DataCollection *aDC1 = new DataCollection();
    DataCollection *aDC2 = new DataCollection();
    DataCollection *aDC3 = new DataCollection();
    DataCollection *aDC4 = new DataCollection();

    // Test case 1 - Empty DataCollection 1
    cout << "Test Case 1 - Just constructed a DataCollection 1:" << endl;
    cout << "Empty DataCollection 1: " << *aDC1 << endl;

    // Test case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1
    cout << "Test Case 2 - Prepending a few elements: 1 2 3 4 5 6 to DataCollection 1:" << endl;
    cout << "              expecting: 6 5 4 3 2 1 in DataCollection 1:" << endl;

    for (unsigned int i = 1; i <= 6; i++)
    {
        try
        {
            cout << "Prepending " << i << " to DataCollection 1" << endl;
            aDC1->prepend(i);
        }
        catch (UnableToInsertException &anException)
        {
            cout << "prepend() unsuccessful because " << anException.what() << endl;
        }
    }
    cout << "Content of DataCollection 1: " << *aDC1 << endl;

    // Test case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2
    cout << "Test Case 3 - Appending a few elements: 1 2 3 4 5 6 to DataCollection 2:" << endl;
    cout << "              expecting: 1 2 3 4 5 6  in DataCollection 2:" << endl;

    for (unsigned int i = 1; i <= 6; i++)
    {
        try
        {
            cout << "Appending " << i << " to DataCollection 2" << endl;
            aDC2->append(i);
        }
        catch (UnableToInsertException &anException)
        {
            cout << "append() unsuccessful because " << anException.what() << endl;
        }
    }
    cout << "Content of DataCollection 2: " << *aDC2 << endl;

    // Test case 4 - Prepending and Appending a few elements to DataCollection 3
    cout << "Test Case 3 - Prepending and Appending a few elements to DataCollection 3:" << endl;
    cout << "              expecting: 3 4 1 2 5 6  in DataCollection 3:" << endl;

    try
    {
        cout << "Appending 1 to DataCollection 3" << endl;
        aDC3->append(1);
    }
    catch (UnableToInsertException &anException)
    {
        cout << "append() unsuccessful because " << anException.what() << endl;
    }
    try
    {
        cout << "Appending 2 to DataCollection 3" << endl;
        aDC3->append(2);
    }
    catch (UnableToInsertException &anException)
    {
        cout << "append() unsuccessful because " << anException.what() << endl;
    }
    try
    {
        cout << "Prepending 4 to DataCollection 3" << endl;
        aDC3->prepend(4);
    }
    catch (UnableToInsertException &anException)
    {
        cout << "append() unsuccessful because " << anException.what() << endl;
    }
    try
    {
        cout << "Prepending 3 to DataCollection 3" << endl;
        aDC3->prepend(3);
    }
    catch (UnableToInsertException &anException)
    {
        cout << "append() unsuccessful because " << anException.what() << endl;
    }
    try
    {
        cout << "Appending 5 to DataCollection 3" << endl;
        aDC3->append(5);
    }
    catch (UnableToInsertException &anException)
    {
        cout << "append() unsuccessful because " << anException.what() << endl;
    }
    try
    {
        cout << "Appending 6 to DataCollection 3" << endl;
        aDC3->append(6);
    }
    catch (UnableToInsertException &anException)
    {
        cout << "append() unsuccessful because " << anException.what() << endl;
    }
    cout << "Content of DataCollection 3: " << *aDC3 << endl;

    // Test case 5 - Testing removefirstandLast on DataCollection 3
    cout << "Test Case 5 - Testing removefirstandLast on DataCollection 3:" << endl;
    cout << "              expecting: 4 1 2 5  in DataCollection 3:" << endl;
    int retData = aDC3->removeFirstandLast();
    cout << "Content of DataCollection 3: " << *aDC3 << endl;
    cout << "The returned data is: " << retData << endl;

    // Test case 6 - Testing lastOdd on DataCollection 3
    cout << "Test Case 6 - Testing lastOdd on DataCollection 3:" << endl;
    cout << "              expecting: 5  in DataCollection 3:" << endl;
    retData = aDC3->lastOdd();
    cout << "Content of DataCollection 3: " << *aDC3 << endl;
    cout << "The returned data is: " << retData << endl;

    // Testing the used tests on the driver
    cout << "Testing the given cases:" << endl;
    cout << endl;
    cout << "Test Case 7 - Testing removeFirstandLast on DataCollection 4:" << endl;
    cout << "              expecting: 10  in DataCollection 4:" << endl;
    aDC4->append(10);
    retData = aDC4->removeFirstandLast();
    cout << "Content of DataCollection 4: " << *aDC4 << endl;
    cout << "The returned data is: " << retData << endl;

    // Test case 3: Create a list with an even number of nodes. For ex. 10,2,3,4. After returning 4, the list should have 2,3.
    cout << "Test Case 3: Create a list with an even number of nodes. For ex. 10,2,3,4. After returning 4, the list should have 2,3." << endl;
    DataCollection *aDC5 = new DataCollection();
    aDC5->append(10);
    aDC5->append(2);
    aDC5->append(3);
    aDC5->append(4);
    cout << "Content of DataCollection 5: " << *aDC5 << endl;
    retData = aDC5->removeFirstandLast();
    cout << "Content of DataCollection 5: " << *aDC5 << endl;
    cout << "The returned data is: " << retData << endl;
    cout << endl;

    // Test case 4: Create a list with an odd number of nodes. For ex. 10,2,3,4,5. After returning 5, the list should have 2,3,4.
    cout << "Test case 4: Create a list with an odd number of nodes. For ex. 10,2,3,4,5. After returning 5, the list should have 2,3,4." << endl;
    DataCollection *aDC6 = new DataCollection();
    aDC6->append(10);
    aDC6->append(2);
    aDC6->append(3);
    aDC6->append(4);
    aDC6->append(5);
    cout << "Content of DataCollection 6: " << *aDC6 << endl;
    retData = aDC6->removeFirstandLast();
    cout << "Content of DataCollection 6: " << *aDC6 << endl;
    cout << "The returned data is: " << retData << endl;
    cout << endl;

    // Test case 5: Create a list with negative values. For ex. -10,-2,-3,-4. After returning -4, the list should have -2,-3.
    cout << "Test case 5: Create a list with negative values. For ex. -10,-2,-3,-4. After returning -4, the list should have -2,-3." << endl;
    DataCollection *aDC7 = new DataCollection();
    aDC7->append(-10);
    aDC7->append(-2);
    aDC7->append(-3);
    aDC7->append(-4);
    cout << "Content of DataCollection 7: " << *aDC7 << endl;
    retData = aDC7->removeFirstandLast();
    cout << "Content of DataCollection 7: " << *aDC7 << endl;
    cout << "The returned data is: " << retData << endl;
    cout << endl;

    // Test case 6: Create a list with all 0 values. For ex. 0,0,0,0. After returning 0, the list should have 0,0
    cout << "Test case 6: Create a list with all 0 values. For ex. 0,0,0,0. After returning 0, the list should have 0,0" << endl;
    DataCollection *aDC8 = new DataCollection();
    aDC8->append(0);
    aDC8->append(0);
    aDC8->append(0);
    aDC8->append(0);
    cout << "Content of DataCollection 8: " << *aDC8 << endl;
    retData = aDC8->removeFirstandLast();
    cout << "Content of DataCollection 8: " << *aDC8 << endl;
    cout << "The returned data is: " << retData << endl;
    cout << endl;

    // Bonus Test Case: Given a list 6,4,1, return the last odd element -> 1
    cout << "Bonus Test Case: Given a list 6,4,1, return the last odd element -> 1" << endl;
    DataCollection *aDC9 = new DataCollection();
    aDC9->append(6);
    aDC9->append(4);
    aDC9->append(1);
    cout << "Content of DataCollection 9: " << *aDC9 << endl;
    retData = aDC9->lastOdd();
    cout << "Content of DataCollection 9: " << *aDC9 << endl;
    cout << "The returned data is: " << retData << endl;
    cout << endl;

    delete aDC1;
    aDC1 = nullptr;

    delete aDC2;
    aDC2 = nullptr;

    delete aDC3;
    aDC3 = nullptr;

    delete aDC4;
    aDC4 = nullptr;

    delete aDC5;
    aDC5 = nullptr;

    delete aDC6;
    aDC6 = nullptr;

    delete aDC7;
    aDC7 = nullptr;

    delete aDC8;
    aDC8 = nullptr;

    delete aDC9;
    aDC9 = nullptr;

    return 0;
}
