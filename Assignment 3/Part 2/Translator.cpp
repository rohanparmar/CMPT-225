/*
 * testDriver.cpp
 *
 * Description: Drives the testing of the BST, the BSTNode,
 *              the WordPair and all the exceptions classes.
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

void display(WordPair &anElement)
{
    cout << anElement;
}

// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[])
{

    Dictionary *testing = new Dictionary();

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
            // insert aWordPair into "testing" using a try/catch block
            try
            {
                testing->put(aWordPair);
            }
            catch (ElementAlreadyExistsException &e)
            {
                // cout << "ElementAlreadyExistsException: " << e.what() << endl;
                cout << "The element " << aWordPair.getEnglish() << " and " << aWordPair.getTranslation() << " already exists in the tree." << endl;
            }
        }
        myfile.close();

        // If user entered "Display" at the command line ...
        if ((argc > 1) && (strcmp(argv[1], "displayContent") == 0))
        {
            // ... then display the content of the BST.
            cout << "Displaying the content of the Dictionary:" << endl;
            testing->displayContent(display);
        }
        else if (argc == 1)
        {
            // while user has not entered CTRL+D
            while (getline(cin, aWord))
            {

                WordPair aWordPair(aWord);
                // retrieve aWordPair from "testing" using a try/catch block
                try
                {
                    translated = testing->get(aWordPair);
                    cout << translated.getEnglish() << " : " << translated.getTranslation() << endl;
                }
                catch (ElementDoesNotExistException &e)
                {
                    // cout << "ElementDoesNotExistException: " << e.what() << endl;
                    // cout << "The element \"" << aWordPair.getEnglish() << "\" does not exist in the tree." << endl;
                    cout << "*̸͈̊̐*̵͚̾̐̄*̷̨͌̌Ǹ̴͇͚̍Ǒ̸̢̞̩̈́͋Ţ̴̙̗̑̋ ̸̢̼̰̊F̶̫͙͂O̵̡̬͔͛͌͘Ů̵̡͔̼͊N̴̛̙͆̽D̷̨̮͍̅͠*̴̧̘́̌*̷̨̻̺̑͘*̶͎̝̩̓" << endl;
                }
                catch (EmptyDataCollectionException &e)
                {
                    cout << "EmptyDataCollectionException: " << e.what() << endl;
                    cout << "The tree is empty." << endl;
                }
                // print aWordPair
                //           cout <<  << endl;
            }
        }
    }
    else
        cout << "Unable to open file";

    return 0;
}
