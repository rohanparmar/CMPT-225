/*
 * testDriver.cpp
 *
 * Description: Drives the testing of the BST, the BSTNode,
 * the WordPair and all the exceptions classes.
 *
 * Author: AL
 * Last Modification Date: Oct. 2022
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

#include "ElementAlreadyExistsException.h"

#include "ElementDoesNotExistException.h"

#include "EmptyDataCollectionException.h"

#include "Dictionary.h"

using std::cin;

using std::cout;

using std::ifstream;

// As you discover what main() does, record your discoveries by commenting the code.

// If you do not like this main(), feel free to write your own.

// Remember, this is a test driver. Feel free to modify it as you wish!

int main(int argc, char *argv[])

{
    Dictionary *book = new Dictionary();
    string aLine = "";
    string aWord = "";
    string englishW = "";
    string translationW = "";
    string filename = "myDataFile.txt";
    string delimiter = ":";
    size_t pos = 0;

    WordPair translated;
    cout << book->getElementCount() << endl;

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
                cout << "Inserting " << englishW << " & " << translationW << " to the list" << endl;
                book->put(aWordPair);
            }

            catch (ElementAlreadyExistsException &anException)
            {
                cout << "insert() unsuccessful because " << anException.what() << endl;
            }
        }
        myfile.close();
    }

    /*cout << "Elementcount = " << book->getElementCount() << endl;

    // If user entered "Display" at the command line ...

    if ( ( argc > 1 ) && ( strcmp(argv[1], "Display") == 0) )

    {

    // ... then display the content of the BST.

    cout << "Displaying the content of the BST:" << endl;

    //Dictionary->displayContent(display);

    }


    else if (argc == 1)

    {

    cout << "English Word: ";

    while( getline(cin, aWord))

    {

    WordPair aWordPair(aWord);

    try

    {

    translated = book->get(aWordPair);

    cout << "Translated: " << translated.getTranslation() << endl;

    cout << endl;

    }

    catch ( ElementDoesNotExistException & anException )

    {

    cout << "retrieve() unsuccessful because " << anException.what() << endl;

    }

    catch ( EmptyDataCollectionException & anException )

    {

    cout << "retrieve() unsuccessful because " << anException.what() << endl;

    }

    }

    }

    }*/

    else
    {
        cout << "Unable to open file" << endl;
    }
    return 0;
}