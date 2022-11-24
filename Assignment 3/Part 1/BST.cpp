/*
 * BST.cpp
 *
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 *
 * Author: Rohan Parmar
 * Date of last modification: 30/10/2022
 */

#include "BST.h"
#include "WordPair.h"

// You cannot change the prototype of the public methods of this class.
// Remember, if you add public methods to this class, our test driver
// - the one we will use to mark this assignment - will not know about them
// since we will use these public method prototypes to create our test driver.

/* Constructors and destructor */

// Default constructor
BST::BST()
{
   root = nullptr;
   elementCount = 0;
}

// Copy constructor
BST::BST(BST &aBST)
{
   root = NULL;
   elementCount = 0;
   if (aBST.root != NULL)
   {
      copyConstructorHelper(aBST.root);
   }
   else
   {
      throw "Error: Cannot copy an empty BST";
   }
}

void BST::copyConstructorHelper(BSTNode *current)
{
   insert(current->element);
   if (current->hasLeft())
   {
      copyConstructorHelper(current->left);
   }
   if (current->hasRight())
   {
      copyConstructorHelper(current->right);
   }
}

// Destructor
BST::~BST()
{
   if (root != nullptr)
   {
      removeNodeRecursively(root);
   }
}

void BST::removeNodeRecursively(BSTNode *current)
{
   if (current->hasLeft())
   {
      removeNodeRecursively(current->left);
   }

   if (current->hasRight())
   {
      removeNodeRecursively(current->right);
   }

   delete current;
   current = nullptr;
}

/* Getters and setters */

// Description: Returns the number of elements currently stored in the binary search tree.
// Time efficiency: O(1)
unsigned int BST::getElementCount() const
{

   return this->elementCount;
}

/* BST Operations */

// Description: Inserts an element into the binary search tree.
//              This is a wrapper method which calls the recursive insertR( ).
// Precondition: "newElement" does not already exist in the binary search tree.
// Exception: Throws the exception "ElementAlreadyExistsException"
//            if "newElement" already exists in the binary search tree.
// Time efficiency: O(log2 n)
void BST::insert(WordPair &newElement)
{
   // Binary search tree is empty, so add the new element as the root
   if (elementCount == 0)
   {
      root = new BSTNode(newElement);
      elementCount++;
   }
   else
   {
      bool inserted = insertR(newElement, root);
      if (!inserted)
      {
         // cout << "BST:insert( )" << *newElement << " already in BST!" << endl; // For testing purposes
         throw ElementAlreadyExistsException("Element already exists in the data collection.");
      }
   }
   return;
}

// Description: Recursive insertion into a binary search tree.
//              Returns true when "anElement" has been successfully inserted into the
//              binary search tree. Otherwise, returns false.
bool BST::insertR(WordPair &anElement, BSTNode *current)
{
   if (current->element == anElement)
   {
      return false;
   }
   else if (anElement < current->element)
   {
      if (current->hasLeft())
      {
         return insertR(anElement, current->left);
      }
      else
      {
         current->left = new BSTNode(anElement);
         elementCount++;
         return true;
      }
   }
   else
   {
      if (current->hasRight())
      {
         return insertR(anElement, current->right);
      }
      else
      {
         current->right = new BSTNode(anElement);
         elementCount++;
         return true;
      }
   }
}

// Description: Retrieves "targetElement" from the binary search tree.
//           This is a wrapper method which calls the recursive retrieveR( ).
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//         if the binary search tree is empty.
// Exception: Throws (propagates) the exception "ElementDoesNotExistException"
//         thrown from the retrieveR(...)
//         if "targetElement" is not in the binary search tree.
// Time efficiency: O(log2 n)
WordPair &BST::retrieve(WordPair &targetElement) const
{

   if (elementCount == 0)
      throw EmptyDataCollectionException("Binary search tree is empty.");

   WordPair &translated = retrieveR(targetElement, root);
   return translated;
}

// Description: Recursive retrieval from a binary search tree.
// Exception: Throws the exception "ElementDoesNotExistException"
//         if "targetElement" is not found in the binary search tree.
WordPair &BST::retrieveR(WordPair &targetElement, BSTNode *current) const
{

   if (current == nullptr)
   {
      throw ElementDoesNotExistException("Element does not exist in the data collection.");
   }
   else if (targetElement < current->element)
   {
      return retrieveR(targetElement, current->left);
   }
   else if (targetElement > current->element)
   {
      return retrieveR(targetElement, current->right);
   }
   else
   {
      return current->element;
   }
}

// Description: Traverses the binary search tree in order.
//           This is a wrapper method which calls the recursive traverseInOrderR( ).
//           The action to be done on each element during the traverse is the function "visit".
// Precondition: Binary search tree is not empty.
// Exception: Throws the exception "EmptyDataCollectionException"
//         if the binary search tree is empty.
// Time efficiency: O(n)
void BST::traverseInOrder(void visit(WordPair &)) const
{

   if (elementCount == 0)
      throw EmptyDataCollectionException("Binary search tree is empty.");

   traverseInOrderR(visit, root);

   return;
}

// Description: Recursive in order traversal of a binary search tree.
void BST::traverseInOrderR(void visit(WordPair &), BSTNode *current) const
{
   if (current != nullptr)
   {
      traverseInOrderR(visit, current->left);
      visit(current->element);
      traverseInOrderR(visit, current->right);
   }
}
