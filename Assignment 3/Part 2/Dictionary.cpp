/*
 * Dictionary.cpp
 *
 * Description: Dictonary data collection ADT class.
 *              BST-based implementation.
 *              Duplicated elements not allowed.
 *
 * Author: AL
 * Author: Rohan Parmar
 * Date of last modification: Oct. 2022
 */

#include "Dictionary.h"

// Description: Default constructor
Dictionary::Dictionary()
{
    root = NULL;
    nodeCount = 0;
}

// Description: Destructor
Dictionary::~Dictionary()
{
    clear();
}

// Description: Returns the number of elements in the dictionary.
// Time Efficiency: O(1)
unsigned int Dictionary::getElementCount() const
{
    return elementCount;
}

// Description: Puts "newElement" (association of key-value) into the Dictionary.
// Precondition: "newElement" does not already exist in the Dictionary.
//               This is to say: no duplication allowed.
// Exception: Throws ElementAlreadyExistsException if "newElement" already exists in the Dictionary.
// Time Efficiency: O(log n)
void Dictionary::insert(WordPair &newElement)
{
    if (root == NULL)
    {
        root = new BSTNode(newElement);
        elementCount++;
    }
    else
    {
        BST::insertR(newElement, root);
    }
}

// Description: Gets "newElement" (i.e., the associated value of a given key) from the Dictionary.
// Precondition: Dictionary is not empty.
// Exception: Throws ElementDoesNotExistException if the key is not found in the Dictionary.
// Exception: Throws EmptyDataCollectionException if the Dictionary is empty.
// Time Efficiency: O(log n)
WordPair &Dictionary::get(WordPair &targetElement) const
{
    if (root == NULL)
    {
        throw EmptyDataCollectionException("Dictionary is empty");
    }
    else
    {
        return getR(targetElement, root);
    }
}

// Description: Prints the content of the Dictionary.
// Time Efficiency: O(n)
void Dictionary::displayContent(void visit(WordPair &)) const
{
    if (root == NULL)
    {
        throw EmptyDataCollectionException("Dictionary is empty");
    }
    else
    {
        displayContentR(visit, root);
    }
}