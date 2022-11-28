/*
 * BSTTestDriver.cpp
 *
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are allowed.
 *
 * Date of last modification: Nov. 2022
 */

#include "BST.h"
#include <iostream>

using namespace std;

int main()
{
    BST *bst = new BST();

    // Printing BST's node count
    cout << "BST's node count: " << bst->numberOfNodes() << endl;

    // Inserting 10 elements into the BST
    bst->insert(15);
    bst->insert(10);
    bst->insert(7);
    bst->insert(25);
    bst->insert(20);
    bst->insert(30);
    bst->insert(5);
    bst->insert(12);
    bst->insert(17);
    bst->insert(22);

    // Printing the BST
    cout << "Printing the BST:" << endl;
    bst->printInOrder();
    cout << endl;

    // Printing BST's node count
    cout << "BST's node count: " << bst->numberOfNodes() << endl;

    // Printing BST's height
    cout << "BST's height: " << bst->height() << endl;

    return 0;
}