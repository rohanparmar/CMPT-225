/*
 * Translator.cpp
 *
 * Description:
 *
 * Author: Elaine Luu
 * Date of last modification: Oct. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
#include "WordPair.h"
#include "Dictionary.h"
#include "ElementAlreadyExistsException.h"
#include "ElementDoesNotExistException.h"
#include "EmptyDataCollectionException.h"

using std::cin;
using std::cout;
using std::ifstream;

void display(WordPair &anElement)
{
   cout << anElement;
}

int main(int argc, char *argv[])
{

   Dictionary *dict = new Dictionary(); // create dictionary object

   string aLine = "";
   string aWord = "";
   string englishW = "";
   string translationW = "";
   string filename = "myDataFile.txt";
   string delimiter = ":";
   size_t pos = 0;
   WordPair translated;

   ifstream myfile(filename);
   if (myfile.is_open())
   {
      cout << "Reading from a file:" << endl;
      while (getline(myfile, aLine))
      {
         pos = aLine.find(delimiter);
         englishW = aLine.substr(0, pos);
         aLine.erase(0, pos + delimiter.length());
         translationW = aLine;
         WordPair aWordPair(englishW, translationW);

         try
         {
            dict->put(aWordPair);
         }
         catch (const std::exception &exc)
         {
            std::cerr << exc.what();
         }
      }
      myfile.close();

      if ((argc > 1) && (strcmp(argv[1], "Display") == 0))
      {
         dict->displayContent(display);
      }
      else if (argc == 1)
      {
         // while user has not entered CTRL+D
         while (getline(cin, aWord))
         {

            WordPair aWordPair(aWord);

            try
            {
               cout << dict->get(aWordPair) << endl;
            }
            catch (ElementDoesNotExistException &e)
            {
               cout << "***Not Found!***" << endl;
            }
         }
      }
   }
   else
      cout << "Unable to open file";

   delete dict;
   dict = NULL;

   return 0;
}